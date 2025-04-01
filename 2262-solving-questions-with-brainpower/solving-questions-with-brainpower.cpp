#define ll long long 
class Solution {
public:
     int n;
     ll f(int i, vector<vector<int>>&q, vector<ll> &dp)
     {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        ll t=q[i][0]+f(i+q[i][1]+1,q,dp);
        ll nt= f(i+1,q,dp);
        return dp[i]=max(t,nt);
     }
    ll mostPoints(vector<vector<int>>& q)
    {
    n= q.size();
    vector<ll> dp(n+1,-1);
    return f(0,q,dp);   
    }
};