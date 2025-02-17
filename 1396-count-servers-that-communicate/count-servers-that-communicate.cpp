class Solution {
public:
    void f(int i,int j,vector<vector<int>>&grid,int &count)
    {
        for(int c=0;c<grid[0].size();c++)
        {
            if(grid[i][c])
            {
                grid[i][c]=0;
                count ++;
                f(i,c,grid,count);
            }
        }
        for(int r=0;r<grid.size();r++)
        {
            if(grid[r][j])
            {
                grid[r][j]=0;
                count ++;
                f(r,j,grid,count);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
     int ans=0;
     for(int i=0;i<grid.size();i++)
     {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j])
            {
                int count=0;
                f(i,j,grid,count);
                if(count>1)
                {
                    ans+=count;
                }
            }
        }
     } 
     return ans;  
    }
};