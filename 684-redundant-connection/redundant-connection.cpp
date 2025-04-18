class DisjointSet
{   private:
    vector<int>parent,rank;
    public:
    DisjointSet(int n)
    {
        for(int i=0;i<=n;i++)
        {
            rank.push_back(0);
            parent.push_back(i);
        }
    }
    int findparent(int x)
    {
        if(x==parent[x])
        {
        return x;
        }
        return parent[x]=findparent(parent[x]);
    }
    void unionbyrank(int u,int v)
    {
        int u1=findparent(u);
        int v1=findparent(v);
        if(rank[u1]>=rank[v1])
        {
            rank[u1]+=rank[v1];
            parent[v1]=u1;
        }
        else if(rank[u1]<rank[v1])
        {
            rank[v1]+=rank[u1];
            parent[u1]=v1;
        }
        else
        {
            rank[v1]+=rank[u1];
            parent[u1]=v1;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
       int n=edges.size();
       DisjointSet ds= DisjointSet(n);
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
        if((ds.findparent(edges[i][0]))!=ds.findparent(edges[i][1]))
        {
            ds.unionbyrank(edges[i][0],edges[i][1]);
        }
        else
        {
            ans=edges[i];
        }
       }
        return ans;   
    }
};