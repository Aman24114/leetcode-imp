class DSU
{
    vector<int>parent,size;
    public:
    DSU(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }
    
    void Union(int u,int v)
    {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
          return ;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int getsize(int node) { return size[node]; }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
      DSU ds(n);
      for(auto it:edges)
      {
        ds.Union(it[0],it[1]);
      }  
      unordered_map<int,int>mp;
      for(auto it:edges)
      {
        mp[ds.findpar(it[0])]++;
      }
      for(int i=0;i<n;i++)
      {
        if(mp.find(ds.findpar(i))==mp.end())
        mp[i]=0;
      }
     int ans=0;
     for(auto it:mp)
     {
        int a=ds.getsize(it.first);
        int b=a*(a-1)/2;
        if(b==it.second)
        {
            ans++;
        }
     }
     return ans;
    }
};