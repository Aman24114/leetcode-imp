class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
    vector<vector<pair<int,double>>>adj(n);
    for(int i=0;i<edges.size();i++)
    {
         adj[edges[i][0]].push_back({edges[i][1], pro[i]});
         adj[edges[i][1]].push_back({edges[i][0], pro[i]});
    } 
     priority_queue<pair<double,int>>pq;
     pq.push({(double)1.0,start});
     vector<double>mx(n,(double)0.0);
     mx[start]=1.0;
     while(!pq.empty())
     {
        auto it=pq.top();
        double prob=it.first;
        int node=it.second;
        pq.pop();
        for(auto &it1:adj[node])
        {
            int node2=it1.first;
            double prob2=it1.second;
            if(mx[node2]<prob*prob2)
            {
            mx[node2]=prob*prob2;
            pq.push({mx[node2],node2});
            }
        }
     }
     return mx[end];
    }
};