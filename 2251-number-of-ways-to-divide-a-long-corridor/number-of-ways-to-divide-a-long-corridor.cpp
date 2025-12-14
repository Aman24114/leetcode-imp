class Solution {
public:
    int mod=1e9+7;
    int numberOfWays(string c) {
    int n=c.size();
    vector<int>ps;
    for(int i=0;i<n;i++)
    {
        if(c[i]=='S')
        ps.push_back(i);
    }
    if(ps.size()%2!=0 ||ps.size()==0)
    return 0;
    long long ans=1;
    int prevend=ps[1];
    for(int i=2;i<ps.size();i+=2)
    {
        int len=ps[i]-prevend;
        ans=(ans*len)%mod;
        prevend=ps[i+1];
    }
    return ans;
    }
};