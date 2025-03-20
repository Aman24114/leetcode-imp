class Solution {
public:
// number & -1= number/
// saare edges ko uthake bus and karte raho to the ultimate parent  
vector<int>parent;
    int find(int x)
    {
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y)
    {
        parent[y]=x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    parent.resize(n);
    vector<int> cost(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        cost[i]=-1;
    }
    for(auto &edge: edges)
    {
        int u= edge[0];
        int v= edge[1];
        int w=edge[2];
        int parentu=find(u);
        int parentv=find(v);
        if(parentu!=parentv)
        {
            Union(parentu,parentv);
            cost[parentu]&=cost[parentv];
        }
        cost[parentu]&=w;   
    }
    vector<int>result;
    for(auto &q: query)
    {
        int s= q[0];
        int t= q[1];
        int parents=find(s);
        int parentt=find(t);
        if(s==t)
        {
            result.push_back(0);
        }
        else if (parents != parentt)
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(cost[parents]);
        }
        
    }
    return result;
    }
};