class Solution {
public:
    int dp[2001][2001];
      bool solve(int i,int prev,vector<int>&nums,int n){
      
        if(i==n-1)
            return true;
        if(i>=n)
            return false;
        if(dp[i][prev]!=-1)
        {
            return dp[i][prev];
        }
        bool ans=false;
        int k=nums[i]-nums[prev];
        for(int j=k-1;j<=k+1;j++)// jumnp
        {   if(j==0)
            continue;
            int jump=nums[i]+j;
             int ind=lower_bound(nums.begin(),nums.end(),jump)-nums.begin();
             if((ind<n)&&(nums[ind]==jump))
             {
                 ans=ans||solve(ind,i,nums,n);
             }
        }
        return dp[i][prev]=ans;
    }
    bool canCross(vector<int>& stones) {
     int n=stones.size();
     if(stones[1]-stones[0]!=1)
     return false;
     memset(dp,-1,sizeof(dp));
     return solve(1,0,stones,n);
    }
};