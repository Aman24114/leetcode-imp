class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
    int i=0,ones=0;
    for(auto it:s)
    {
        if(it=='1')
        ones++;
    }
    s="1"+s+"1";
    int n=s.size();
    vector<int>zerocnt;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            cnt++;
        }
        else 
        {
        if(cnt>0)
        {
            zerocnt.push_back(cnt);
        }
        cnt=0;
        }
    }
    int ans=0,maxi=0;
    int n1=zerocnt.size();
    if(n1>=2)
    {
    for(int i=0;i<n1-1;i++)
    {
        maxi=max(maxi,zerocnt[i]+zerocnt[i+1]);
    }
    }
     ans=ones+maxi;
    return ans;
    }
};