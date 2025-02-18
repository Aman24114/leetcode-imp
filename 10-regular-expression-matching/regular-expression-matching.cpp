class Solution {
public:
    bool isMatch(string s, string p) {
    if(p.length()==0)
    return s.length()==0;
    bool one=false;
    if(s.length()>0 && (p[0]==s[0] || p[0]=='.'))
    {
        one=true;
    }
    if(p.length()>=2 && p[1]=='*')
    {
        return (isMatch(s,p.substr(2))||(one && isMatch(s.substr(1),p)));
    }
    else
    {
        return (one && isMatch(s.substr(1),p.substr(1)));
    }
    }
};