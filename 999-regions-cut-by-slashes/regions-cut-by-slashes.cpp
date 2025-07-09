class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    void  dfs(vector<vector<int>>&grid1,int i,int j)
    {
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size()||  grid1[i][j]!=0)
        {
           return;
        }
        grid1[i][j]=1;
       for (auto& it : dir) {
        int newi = i + it[0];
        int newj = j + it[1];
        dfs(grid1, newi, newj);
    } 
    }
    int regionsBySlashes(vector<string>& grid) {
    // forward slash aur backward slash dono ko 3*3 ka matrix bano aur dfs lagao
    int row=grid.size();
    int col=grid[0].size();
    vector<vector<int>>grid1(row*3,vector<int>(col*3,0));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]=='/')
            {
               grid1[i*3][j*3+2]=1;
               grid1[i*3+1][j*3+1]=1;
               grid1[i*3+2][j*3]=1; 
            }
            else if(grid[i][j]=='\\')
            {
               grid1[i*3][j*3]=1;
               grid1[i*3+1][j*3+1]=1;
               grid1[i*3+2][j*3+2]=1; 
            }
        }
    }
    int ans=0;
    for(int i=0;i<grid1.size();i++)
    {
        for(int j=0;j<grid1[0].size();j++)
        {
            if(grid1[i][j]==0)
            {
                dfs(grid1,i,j);
                ans++;
            }
        }
    }
    return ans;
    }
};