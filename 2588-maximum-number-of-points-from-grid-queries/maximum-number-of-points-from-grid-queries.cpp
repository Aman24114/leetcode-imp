class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& que) {
    int m=grid.size();
    int n=grid[0].size();
    int q=que.size();
    vector<int>ans(q,0);
    vector<pair<int,int>>q1;
    for(int i=0;i<q;i++)
    {
        q1.push_back({que[i],i});
    }
    sort(q1.begin(),q1.end());
    priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    int point=0;
    pq.push({grid[0][0],0,0});
    vis[0][0]=true;
    for(int i=0;i<q;i++)
    {   
        int val=q1[i].first;
        int idx=q1[i].second;
        while(!pq.empty() && pq.top()[0]<val)
        {
            int i1=pq.top()[1];
            int j1=pq.top()[2];
            pq.pop();
            point++;
            for(auto &d:dir)
            {
                int r=i1+d[0];
                int c=j1+d[1];
                if(r>=0 && r<m && c>=0 && c<n && !vis[r][c])
                {
                    pq.push({grid[r][c],r,c});
                    vis[r][c]=true;
                }
            }
        }
        ans[idx]=point;
    }
    return ans;
    }
};