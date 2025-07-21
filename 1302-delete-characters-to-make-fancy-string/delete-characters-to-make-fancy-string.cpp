class Solution {
public:
    string makeFancyString(string s) {
    string a;
    int c=1;
    a+=s[0];
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])
        c++;
        else
        c=1;
        if(c<3)
        a+=s[i];
    }
    return a;    
    }
};