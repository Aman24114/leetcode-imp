#define ll long long 
ll mod= 1e9+7;
class Solution {
public:
    ll f(int i,int t,vector<vector<int>>&types,vector<vector<ll>>&dp)
    {
       if(i==types.size()||t<=0)
       {
        if(t==0)
        return 1;
        return 0;
       }
       if(dp[i][t]!=-1)
       return dp[i][t];
       ll take= 0;
       ll nt=f(i+1,t,types,dp)%mod;
       for(int c=1;c<=types[i][0];c++)
       {
        if(t-(c*types[i][1])<0)
        break;
        take+=f(i+1,t-(c*types[i][1]),types,dp)%mod;
       }
       return dp[i][t]=(take%mod + nt%mod);
    }
    int waysToReachTarget(int t, vector<vector<int>>& types) {
    int n=types.size();
    vector<vector<ll>>dp(n+1,vector<ll>(t+1,-1));
    return f(0,t,types,dp)%mod;
    }
};