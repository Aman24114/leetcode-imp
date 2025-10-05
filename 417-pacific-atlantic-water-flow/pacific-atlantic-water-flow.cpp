class Solution {
public:
     void f(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j)
     {
        int m = h.size();
        int n = h[0].size();
        vis[i][j] = true; 
        if (i-1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j])
        f(h,vis,i-1,j);
        if (i+1 < m && vis[i+1][j] != true && h[i+1][j] >= h[i][j])
        f(h,vis,i+1,j);
        if (j-1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j])
        f(h,vis,i,j-1);
        if (j+1 < n && vis[i][j+1] != true && h[i][j+1] >= h[i][j])
        f(h,vis,i,j+1);
    }  
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h)
    { 
        vector<vector<int>>ans;
        int m=h.size();
        int n=h[0].size();
        vector<vector<bool>>p(m,vector<bool>(n,0));
        vector<vector<bool>>a(m,vector<bool>(n,0));
        for (int i=0;i<m;i++) 
        {    
            f(h,p,i,0);
            f(h,a,i,n-1);
        }
        for (int j=0;j<n;j++)
        {    
            f(h,p,0,j);
            f(h,a,m-1,j);
        }
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (p[i][j] && a[i][j]) 
                ans.push_back({i,j});         
            }
        }
        return ans;
    }  
};