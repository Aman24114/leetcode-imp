struct trienode
{
    trienode* children[26];
    bool isendofword;
};
class WordDictionary {
public:
    trienode*getnode()
    {
        trienode* newnode=new trienode();
        newnode->isendofword=false;
        for(int i=0;i<26;i++)
        {
            newnode->children[i]=NULL;
        }
        return newnode;
    }  
    trienode* root;
    WordDictionary() {
    root=getnode();
    }
    
    void addWord(string word) {
    trienode* crawler=root;
    for(int i=0;i<word.length();i++)
    {
        int index=word[i]-'a';
        if(!crawler->children[index])
        {
            crawler->children[index]=getnode();
        }
        crawler=crawler->children[index];
    }
    crawler->isendofword=true;
    }
    bool f1(trienode* root,string word)
    {
        trienode*crawler=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(ch=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(crawler->children[j]!=NULL)
                    {
                       if(f1(crawler->children[j],word.substr(i+1))==true)
                       {
                         return true;
                       }
                    }
                }
                return false;
            }
            if(crawler->children[ch-'a']==NULL)
            {
                return false;
            }
            crawler=crawler->children[ch-'a'];
        }
            return (crawler!=NULL && crawler->isendofword);
        }
    bool search(string word) {
    return  f1(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */