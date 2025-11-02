#define ll long long 
class Solution {
public:
    void dfs(vector<vector<int>>&grid,int x,int y,int m,int n,int d)
    {
        if(x<0 || x>=m || y<0 || y>=n)
        return;
        if(grid[x][y]==2 || grid[x][y]==1)
        return;
        grid[x][y]=3;
        if(d==1)
        dfs(grid,x+1,y,m,n,d);
        if(d==2)
        dfs(grid,x,y+1,m,n,d);
        if(d==3)
        dfs(grid,x-1,y,m,n,d);
        if(d==4)
        dfs(grid,x,y-1,m,n,d);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
    vector<vector<int>>grid(m,vector<int>(n,0));
    for(int i=0;i<g.size();i++){
    int x=g[i][0];
    int y=g[i][1];
    grid[x][y]=1;
    }
    
    for(int i=0;i<w.size();i++){
    int x=w[i][0];
    int y=w[i][1];
    grid[x][y]=1;
    }

    for(int i=0;i<g.size();i++){
    int x=g[i][0];
    int y=g[i][1];
    dfs(grid,x+1,y,m,n,1);
    dfs(grid,x,y+1,m,n,2);
    dfs(grid,x-1,y,m,n,3);
    dfs(grid,x,y-1,m,n,4);
    }
    ll cnt=0;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    if(grid[i][j]==0)
    cnt++;
    }
    }   
    return cnt;
    }
};