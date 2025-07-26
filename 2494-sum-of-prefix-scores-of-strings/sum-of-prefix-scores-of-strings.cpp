struct trienode
{
    int countp=0;
    trienode* children[26];
};
class Solution {
public:
    trienode* getrienode()
    {
        trienode* newnode=new trienode();
        for(int i=0;i<26;i++)
        {
            newnode->children[i]=NULL;
        }
        newnode->countp=0;
        return newnode;
    }
    void insert(string &word,trienode* root)
    {
       trienode* crawl=root;
       for(char ch:word)
       {
        int idx=ch-'a';
        if(crawl->children[idx]==NULL)
        {
          crawl->children[idx]=getrienode();  
        }
        crawl->children[idx]->countp+=1;
        crawl=crawl->children[idx];
       } 
    }
    int getscore(string& word,trienode* root)
    {
        trienode* crawl=root;
        int score=0;
        for(char ch:word)
        {  
            int idx=ch-'a';
            score+=crawl->children[idx]->countp;
            crawl=crawl->children[idx];
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
    int n=words.size();
    trienode* root=getrienode();
    for(auto it:words)
    {
        insert(it,root);
    }
    vector<int>result(n);
    for(int i=0;i<n;i++)
    {
        result[i]=getscore(words[i],root);
    }
    return result;
    }
};