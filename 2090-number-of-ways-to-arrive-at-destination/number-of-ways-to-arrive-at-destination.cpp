#define ll long long 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
        {
        vector<vector<pair<ll, ll>>> adj(n); 
        for (auto& it : roads)
         {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> pq; // minheap lelenege
        vector<ll> dist(n, LLONG_MAX);  
        vector<ll> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        const ll mod = 1e9 + 7;
        while (!pq.empty()) 
        {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for (auto& it : adj[node]) 
            {
                ll adjnode = it.first;
                ll edw = it.second;
                if (dis + edw < dist[adjnode])
                {  
                    dist[adjnode] = dis + edw;
                    pq.push({dis + edw, adjnode});
                    ways[adjnode] = ways[node];
                } else if (dis + edw == dist[adjnode]) 
                {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};