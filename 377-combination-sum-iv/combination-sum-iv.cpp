class Solution {
public:
//   return the number of possible combinatins that add up to the target
     int func(vector<int>&nums,int n,int sum,int target,vector<int> dp)
      {   if(sum==target)
          return 1;
          if(sum>target)
          return 0;
          if(dp[sum]!=-1)
         { 
           return dp[sum];
         }
           int sol=0;
          for(int i=0;i<n;i++)
          {
             sol+=func(nums,n,sum+nums[i],target,dp);
          }
          return dp[sum]=sol;
    }
     int combinationSum4(vector<int>& nums, int target) { 
     // target=[1,2,3],target=4;
     // the possible combinations
     vector<unsigned int> dp(target+1,0);
     dp[0]=1;
     for(int i=1;i<=target;i++)
    {
     for(int j=0;j<nums.size();j++)
    {
        if(i-nums[j]>=0)
        {
            dp[i]+=dp[i-nums[j]];
        }
    }
   }
   return dp[target];     
    }
};