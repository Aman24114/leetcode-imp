class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=1;j++)
        {
            int ans=0;
            if(j==0)
            {
                ans=max(0+dp[i+1][0],-prices[i]+dp[i+1][1]);
            }
            if(j==1)
            {
                ans=max(0+dp[i+1][1],prices[i]-fee+dp[i+1][0]);
            }
            dp[i][j]=ans;
        }
    }
   return dp[0][0];
    }
};