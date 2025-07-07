class Solution {
public:
    void dfs(int node,vector<int>&res,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&vis)
    {
        res.push_back(node);
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,res,adj,vis);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& ap) {
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>vis;
    vector<int>res;
    int st;
    for(int i=0;i<ap.size();i++)
    {
      int u=ap[i][0];
      int v=ap[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      vis[v]=0;
      vis[u]=0;
    }
    for(auto it:adj)
    {
        if(it.second.size()==1)
        {
            dfs(it.first,res,adj,vis);
            break;
        }
    }  
    return res;  
    }
};