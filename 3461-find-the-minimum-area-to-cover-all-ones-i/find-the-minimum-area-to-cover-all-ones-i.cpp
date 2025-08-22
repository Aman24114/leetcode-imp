class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int rl=n,rm=-1,cl=m,cm=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                rl=min(rl,i);
                rm=max(rm,i);
                cl=min(cl,j);
                cm=max(cm,j);
            }
        }
    }  
    int h=(rm-rl+1);
    int w=(cm-cl+1);;
    return h*w;
    }
};