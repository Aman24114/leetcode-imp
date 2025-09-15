class Solution {
public:
    bool f(string ch,string bl)
    {
        vector<int>freq(26,0);
        for(auto it:bl)
        {
            freq[it-'a']++;
        }
        for(auto it:ch)
        {
            if(freq[it-'a'])
            return 0;
        }
        return 1;
    }
    int canBeTypedWords(string text, string bl) {
    int ans=0;
    string ch;
    stringstream s(text);
    while(getline(s,ch,' '))
    {
        bool temp=f(ch,bl);
        if(temp)
        ans++;
    }   
    return ans;
    }
};