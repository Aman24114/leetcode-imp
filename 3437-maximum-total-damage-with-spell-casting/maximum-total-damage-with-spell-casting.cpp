// tc = m log m + n
// sc = o m
#define ll long long 
class Solution {
public:
    ll f(int idx,vector<pair<ll,ll>> &v,vector<ll>&dp)
    {
        if(idx>=v.size())
        return 0;

        if(dp[idx]!=-1)
        return dp[idx];

        ll nt=f(idx+1,v,dp);

        int j=idx+1;
        while(j<v.size() && v[j].first <=v[idx].first+2)
        j++;

        ll t= v[idx].second+f(j,v,dp);

        return dp[idx]=max(t,nt);
    }
    ll maximumTotalDamage(vector<int>& power) {
    int n=power.size();
    map<ll,ll>mp;
    for(int i=0;i<n;i++)
    {
        mp[power[i]]+=power[i];
    }
    vector<pair<ll,ll>>v;
    for(auto it:mp)
    {
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end()); 
    vector<ll>dp(v.size(),-1);
    return f(0,v,dp);
    }
};