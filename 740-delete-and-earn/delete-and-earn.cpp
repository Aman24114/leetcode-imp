class Solution {
public:
    int f(int i,vector<int>&sum,vector<int>&dp)
    {
        if(i==0)
        return sum[0];
        if(i<0)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int t=sum[i]+f(i-2,sum,dp);
        int nt=f(i-1,sum,dp);
        return dp[i]=max(t,nt);
    }
    int deleteAndEarn(vector<int>& nums) {
    int n=1e4+1;
    vector<int>sum(n,0);
    for(auto it:nums)
    {
        sum[it]+=it;
    } 
    vector<int>dp(n,-1);
    int m=sum.size();
    return f(m-1,sum,dp);
    }
};