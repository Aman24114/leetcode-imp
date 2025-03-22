class Solution {
public:
    void dfs(int i,vector<vector<int>>&graph,vector<bool>&vis,int &node,int &sum)
    {
        vis[i]=true;
        node++;
        sum+=graph[i].size();
        for(int adj:graph[i])
        {
            if(!vis[adj])
            {
             dfs(adj,graph,vis,node,sum);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>>graph(n);
    for(auto ed:edges)
    {
        graph[ed[0]].push_back(ed[1]);
        graph[ed[1]].push_back(ed[0]);
    }
    vector<bool>vis(n,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
        continue;
        int node=0,sum=0;
        dfs(i,graph,vis,node,sum);
        if(sum == node*(node-1))
        ans++;
    }
     return ans;
    }
};