class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
     vector<vector<int>>adj(n);
     for(auto e:edges)
     {
        adj[e[0]-1].push_back(e[1]-1);
        adj[e[1]-1].push_back(e[0]-1);
     }   
     vector<pair<int,int>>dist(n,{1e9,1e9}); // shortest aur 2nd shroted ke liye lenge
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     dist[0]={0,1e9};
     pq.push({0,0});
     while(!pq.empty())
     {
        auto[currtime,node]=pq.top();
        pq.pop();
        if(currtime>dist[node].second)
        {
            continue;
        }
        int newtime=currtime+time;
        int t=currtime/change;
        if(t%2==1)
        {
            newtime=(t+1)*change+time;
        }
        for(auto it1:adj[node])
        {
           if(dist[it1].first >newtime)
           {
            dist[it1].second=dist[it1].first;
            dist[it1].first=newtime;
            pq.push({dist[it1].first, it1}); 
           }
           else if(dist[it1].first == newtime)
           continue;
           else if(dist[it1].second>newtime)
           {
            dist[it1].second=newtime;
            pq.push({dist[it1].second,it1});
           }
        }
     }
     return dist[n-1].second;
    }
};