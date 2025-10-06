class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int swimInWater(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    priority_queue<p,vector<p>,greater<p>> pq;// min heap lenge    
    int time=0;
    dist[0][0]=grid[0][0];
    pq.push({grid[0][0],{0,0}});
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int time=it.first;
        int r=it.second.first;
        int c= it.second.second;
        if(r==n-1 && c==m-1)
        {
            return time;
        }
        for(int ind=0;ind<4;ind++)
        {
        int nrow=r+dr[ind];
        int ncol=c+dc[ind];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m)
        { 
            int newtime=grid[nrow][ncol]-time;
            if(newtime>0)
            newtime=newtime+time;
            else
            newtime=time;
            if(dist[nrow][ncol]>newtime)
            {
                dist[nrow][ncol]=newtime;
                pq.push({newtime,{nrow,ncol}});
            }
        }
        }
    }
    return -1;
    }
};