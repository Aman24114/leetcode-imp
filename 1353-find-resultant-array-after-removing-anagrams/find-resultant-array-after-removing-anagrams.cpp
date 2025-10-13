class Solution {
public:
    string f(string word)
    {
        int freq[26]={0};
        for(char ch:word)
        {
            freq[ch-'a']++;
        }
        string s="";
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {  
               s+=('a'+i);
               s+=to_string(freq[i]);
            }
        }
        return s;
    }
    vector<string> removeAnagrams(vector<string>& words) {
    vector<string>result;
    for(auto it:words)
    {
        if(result.empty() || f(result.back())!=f(it))
        result.push_back(it);
    }    
    return result;
    }
};