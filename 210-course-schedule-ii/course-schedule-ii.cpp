class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
     vector<vector<int>>adj(n);
     vector<int>indegree(n,0);
     vector<int>ans;
     for(auto &it:p)
     {
        int a=it[0];
        int b=it[1];
        adj[b].push_back(a);
        indegree[a]++;
     }   
     queue<int>q;
     for(int i=0;i<n;i++)
     {
        if(indegree[i]==0)
        q.push(i);
     }
     while(!q.empty())
     {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int ne:adj[node])
        {
            indegree[ne]--;
            if(indegree[ne]==0)
            q.push(ne);
        }
     }
     if(ans.size()!=n)
     return {};
     return ans;
    }
};