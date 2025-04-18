class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
    vector<vector<pair<int,int>>>graph(n+1);
    for(auto it:times)
    {
        int src=it[0],des=it[1],time=it[2];
        graph[src].push_back({des,time});
    }  
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1,INT_MAX);
    dist[k]=0;
    pq.push({0,k});
    while(!pq.empty())
    {
        auto it=pq.top();
        int  cost=it.first;
        int node=it.second;
        pq.pop();
        if(cost>dist[node])
        continue;
        for(auto &[ne,w]:graph[node])
        {
        if(cost+w<dist[ne])
        {
            dist[ne]=cost+w;
            pq.push({dist[ne],ne});
        }
       }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INT_MAX)
        return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
    }
};