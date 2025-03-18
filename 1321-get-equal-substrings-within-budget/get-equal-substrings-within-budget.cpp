class Solution {
public:
    int equalSubstring(string s, string t, int maxc) {
    int i=0,j=0;
    int curr=0,maxlen=0;
    while(j<s.length())
    {
        curr+=abs(s[j]-t[j]);
        while(curr>maxc)
        {
            curr-=abs(s[i]-t[i]);
            i++;
        }
        maxlen=max(maxlen,j-i+1);
        j++;
    }  
    return maxlen;
    }
};