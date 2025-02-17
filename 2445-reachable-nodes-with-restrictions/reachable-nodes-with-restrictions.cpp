class Solution {
public:
    void dfs(int node,vector<vector<int>>&graph,set<int>&s,int &ans,vector<bool>&visited)
    {
        visited[node]=true;
        for(auto &it : graph[node])
        {
            if(!visited[it])
            {
                if(!visited[it]&& s.find(it)==s.end())
               { ans++;
                dfs(it,graph,s,ans,visited);
                }
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
     vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        set<int> s(r.begin(), r.end());
        int ans = 1; 
        dfs(0, graph, s, ans, visited);
        return ans;
    }
};