class Solution {
public:
      void dfs(string node, string des, double prod, double& ans, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& vis) {
        if (vis.find(node) != vis.end())
            return;
        vis.insert(node);
        if (node == des) {
            ans = prod;
            return;
        }
        for (auto it : adj[node]) { 
            string adjnode = it.first;
            double val = it.second;
            dfs(adjnode, des, prod * val, ans, adj, vis);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
    int n= eq.size();
    unordered_map<string, vector<pair<string, double>>> adj;
    for(int i=0;i<n;i++)
    {
        string u=eq[i][0];
        string v=eq[i][1];
        double w=val[i];
        adj[u].push_back({v,w});
        adj[v].push_back({u,1/w});
    }   
    vector<double> result;
    for(auto it : q)
    {
        string src= it[0];
        string des=it[1];
        double ans=-1.0;
        unordered_set<string> vis;
        double prod=1.0;
        if(adj.find(src)!=adj.end())
        dfs(src,des,prod,ans,adj,vis);
        result.push_back(ans);
    }
    return result;
    }
};