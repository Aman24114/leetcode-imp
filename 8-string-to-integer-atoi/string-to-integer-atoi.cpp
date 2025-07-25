class Solution {
public:
    int myAtoi(string s) {
    s.erase(0,s.find_first_not_of(' '));
    if(s.empty())
    return 0;
    int i=0,num=0,sign=1;
    if(s[0]=='+'|| s[0]=='-')
    {
        sign=(s[0]=='-')?-1:+1;
        i++;
    }
    while(i<s.length() && isdigit(s[i]))
    {
        int dig=s[i]-'0';
        if(num >(INT_MAX-dig)/10)
        {
            return (sign==1)? INT_MAX:INT_MIN ;
        }
        num=num*10 +dig;
        i++;
    }
    return sign*num;
    }
};
