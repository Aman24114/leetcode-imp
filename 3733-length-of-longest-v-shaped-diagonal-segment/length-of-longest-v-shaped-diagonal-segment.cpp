class Solution {
public:
    int m,n;
    vector<vector<int>>direc={{1,1},{1,-1},{-1,-1},{-1,1}};
    int f(int i,int j,int d,bool canturn,int val, vector<vector<int>>&grid)
    {
        int i1=i+direc[d][0];
        int j1=j+direc[d][1];
        if(i1<0 || i1>=m || j1<0 || j1>=n || grid[i1][j1]!=val)
        {
            return 0;
        }
        int ans=0;
        int keepmoving = 1+f(i1,j1,d,canturn,val==2?0:2,grid);
        ans=max(ans,keepmoving);
        if(canturn==true)
        {
           int turn=max(keepmoving,1+f(i1,j1,(d+1)%4,false,val==2?0:2,grid));
           ans=max(ans,turn);
        }
        return ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
    m=grid.size();
    n=grid[0].size();
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
                for(int d=0;d<=3;d++)
                {
                    ans=max(ans,1+f(i,j,d,true,2,grid));
                }
            }
        }
    }
    return  ans;
    }
};