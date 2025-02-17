class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int dp[51][51][51];
    int findPaths(int m, int n, int move, int sr, int sc) {
    memset(dp,0,sizeof(dp));
    for(int k=1;k<=move;k++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(vector<int>it:dir)
                {
                    int x=i+it[0];
                    int y=j+it[1];
                    if(x<0 || x>=m || y<0 || y>=n)
                    {
                        dp[i][j][k]=(1+dp[i][j][k])%mod;
                    }
                    else
                    {
                        dp[i][j][k]=(dp[i][j][k]+dp[x][y][k-1])%mod;
                    }
                }
            }
        }
    }
    return dp[sr][sc][move];
    }
};