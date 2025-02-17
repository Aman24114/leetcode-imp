class DisjointSet
{   vector<int> rank , parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findUPar(int node)
    {
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u , int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;;
            rank[ulp_u]++;
        }
    }

};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      DisjointSet ds(isConnected.size());
      for(int i=0;i<isConnected.size();i++)
      {
        for(int j=0;j<isConnected.size();j++)
        {
            if(isConnected[i][j]==1)
            {
                ds.unionByRank(i,j);
            }
        }
      }
      set<int>pq;
      for(int i=0;i<isConnected.size();i++)
      {
        pq.insert(ds.findUPar(i));
      }  
      return pq.size();
    }
};