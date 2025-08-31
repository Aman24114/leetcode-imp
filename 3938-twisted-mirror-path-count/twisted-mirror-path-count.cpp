#define ll long long 
class Solution {
public:
    int mod=1e9+7;
    int m,n;
    ll dp[500][500][3];
    ll f(int i,int j,vector<vector<int>>&grid,int dir)
    {
        if(i==n-1  && j==m-1)
        return 1LL;
        if(i>=n || j>=m)
        return 0LL;
        if(dp[i][j][dir]!=-1) 
        return dp[i][j][dir];
        if(grid[i][j]==1)
        {
            if(dir==0)
            {
                return dp[i][j][dir]=f(i+1,j,grid,1)%mod;
            }
            else
            {
                return dp[i][j][dir]=f(i,j+1,grid,0)%mod;
            }
        }
        ll right=f(i,j+1,grid,0)%mod;
        ll down=f(i+1,j,grid,1)%mod;
        return dp[i][j][dir]=(right+down)%mod;

    }
    int uniquePaths(vector<vector<int>>& grid) {
    n=grid.size();
    m=grid[0].size();
    memset(dp,-1,sizeof(dp));
    return f(0,0,grid,2);    
    }
};