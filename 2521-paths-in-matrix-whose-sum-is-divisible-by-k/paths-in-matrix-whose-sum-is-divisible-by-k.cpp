class Solution {
public:
    int mod=1e9+7;
    int f(vector<vector<int>> &grid,int i,int j,int n,int m,int k,int r,vector<vector<vector<int>>> &dp)
    { if(i==n-1 && j==m-1)
      return (r+grid[i][j])%k == 0 ? 1:0;
      if(i>=n || j>=m)
      return 0;
      if(dp[i][j][r]!=-1)
      return dp[i][j][r];
      int ans=0;
      ans=(ans+f(grid,i+1,j,n,m,k,(r+grid[i][j])%k,dp))%mod;
      ans=(ans+f(grid,i,j+1,n,m,k,(r+grid[i][j])%k,dp))%mod;
      return dp[i][j][r]=ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
    return f(grid,0,0,n,m,k,0,dp);  
    }
};