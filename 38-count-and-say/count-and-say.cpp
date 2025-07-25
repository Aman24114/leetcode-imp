class Solution {
public:
    string countAndSay(int n) {
    if(n==1)
    return "1";
    string result="";
    string s=countAndSay(n-1);
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        int cnt=1;
        while(i<s.length()-1 && s[i]==s[i+1])
        {
            cnt++;
            i++;
        }
        result+=to_string(cnt)+ch;
    }    
    return result;
    }
};