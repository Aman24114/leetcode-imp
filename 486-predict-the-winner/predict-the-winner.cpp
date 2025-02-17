class Solution {
public:
    int f(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)
        return nums[i];
        if(i>j)
        return 0;
        if((dp[i][j])!=-1)
        {
            return dp[i][j];
        }
     int s= nums[i]-f(nums,i+1,j,dp);
     int e= nums[j]-f(nums,i,j-1,dp);
     return dp[i][j]=max(s,e);
    }
    bool predictTheWinner(vector<int>& nums) {
     int n=nums.size();
     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     int ans=f(nums,0,n-1,dp);
     if(ans>=0){
            return true;
        }else{
            return false;
        }
        
    }
};