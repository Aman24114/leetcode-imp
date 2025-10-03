class Solution{
public:
typedef pair<int,pair<int,int>> p;
vector<vector<int>>dir ={{0,1},{1,0},{0,-1},{-1,0}}; 
int trapRainWater(vector<vector<int>>&h)
{
    int m = h.size();
    int n = h[0].size();
    priority_queue<p,vector<p>,greater<p>>pq; //minheap
    vector<vector<bool>> vis(m,vector<bool>(n,false)); // visited check

    for (int row=0;row<m;row++)
    {
        for(int col:{0,n-1})
        {
            pq.push({h[row][col],{row,col}}); // pushing colm boundary and marking visited 
            vis[row][col]=true;
        }
    }

    for (int col=0;col<n;col++)
    {
        for (int row:{0,m-1})
        {
            pq.push({h[row][col],{row,col}}); // pushing row boundary and marking visited 
            vis[row][col]=true;
        }
    }
    // now doing bfs 
    int w=0;
    while (!pq.empty()) 
    {
        auto cur=pq.top();
        pq.pop();
        int h1=cur.first;
        int i=cur.second.first;
        int j=cur.second.second;
        for (vector<int>d:dir) 
        {
            int i1=i+d[0];
            int j1=j+d[1];
            if (i1>=0 && i1<m && j1>=0 && j1<n && !vis[i1][j1])
            {
                w+=max(h1-h[i1][j1],0);
                pq.push({max(h1,h[i1][j1]),{i1,j1}});
                vis[i1][j1] = true;
            }
        }
    }
    return w;
}
};