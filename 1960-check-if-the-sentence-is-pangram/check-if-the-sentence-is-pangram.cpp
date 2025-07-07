class Solution {
public:
    bool checkIfPangram(string s)
    {
        int l = s.length();
        if(l<26)
        {
            return false;
        }
        int ch[26];
        for(int i=0;i<l;i++)
        {
            ch[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(ch[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};