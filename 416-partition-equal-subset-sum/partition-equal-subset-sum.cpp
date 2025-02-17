class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int n= nums.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
     sum+=nums[i];
    }
    if(sum%2==1)
    {
     return false;
    }
    else
    {
    int k= sum/2;
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true; // frist col true 
    }
    if(nums[0]<=k)
    dp[0][nums[0]]=true;
        for(int i=1;i<n;i++)
        {
        for(int t=1;t<=k;t++)
        {
        bool nt= dp[i-1][t];
        bool ta= false;
        if(nums[i]<=t)
        {
        ta=dp[i-1][t-nums[i]];
        }
        dp[i][t]=nt||ta;
        }
        }
    return dp[n-1][k];
    }
    return false; 
    }
};