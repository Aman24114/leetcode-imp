class Solution {
public:
    bool f(int n,int target,vector<int>&nums)
    {
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++)
        {
          dp[i][0]=true;
        }
          if(nums[0]<=target)
          {
            dp[0][nums[0]]=true;
          }  
          for(int i=1;i<n;i++)
          {
            for(int t=1;t<=target;t++)
            {
                bool nt=dp[i-1][t];
                bool take=false;
                if(nums[i]<=t)
                {
                    take=dp[i-1][t-nums[i]];
                }
                dp[i][t]=nt||take;
            }
          }
         return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    } 
    if(sum %2==1)
    return false;
    int target= sum/2;
    int n=nums.size();
    if(f(n,target,nums))
    {
        return true;
    }
    return false;
    }
};