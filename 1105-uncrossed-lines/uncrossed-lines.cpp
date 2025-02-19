class Solution {
public:
    int f(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp)
    {    int n=nums1.size();
         int m=nums2.size();
        if(i>=n || j>=m)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        int take=0,a1,b1,nt;
        if(nums1[i]==nums2[j])
        {
         take=1+f(nums1,nums2,i+1,j+1,dp);
        }
        else
        {
         a1=f(nums1,nums2,i+1,j,dp);
         b1=f(nums1,nums2,i,j+1,dp);
         nt=max(a1,b1);
        }
        return dp[i][j]=max(take,nt);
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(nums1,nums2,0,0,dp);
    }
};