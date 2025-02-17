class Solution {
public:
int coinChange(vector<int>& coins, int target) {
int n = coins.size();
vector<vector<int>>dp(n,vector<int>(target+1,0));
for(int i=0;i<=target;i++)
{
    if(i%coins[0]==0)
    dp[0][i]=i/coins[0];
    else
    dp[0][i]=1e9;
}
for(int i=1;i<n;i++)
{
    for(int t=0;t<=target;t++)
    {
        int nottake=dp[i-1][t];
        int take=1e9;
        if(coins[i]<=t)
        {
            take=1+dp[i][t-coins[i]];
        }
        dp[i][t]=min(take,nottake);
    }
}
int ans=dp[n-1][target];
if(ans>=1e9)
return -1;
else
return ans;
}
};