class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k, vector<int>(k, 0));
        int maxi=0;
        for (auto it:nums)
        {
            for (int j=0; j<k;++j)
            {
                int r= it%k;
                maxi = max(maxi,dp[r][j]=dp[j][r]+1);
            }
        }
        return maxi;
    }
};