class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int node1, int node2) {
        int parent1 = findUltimateParent(node1);
        int parent2 = findUltimateParent(node2);

        if (parent1 == parent2) return;
        if (rank[parent1] < rank[parent2]) {
            parent[parent1] = parent2;
        } else if (rank[parent2] < rank[parent1]) {
            parent[parent2] = parent1;
        } else {
            parent[parent2] = parent1;
            rank[parent1]++;
        }
    }
};
class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
      int cc=0;
      int e=0;
      DisjointSet ds(n);
      for(auto it : connections)
      {
        int u=it[0];
        int v=it[1];
        if(ds.findUltimateParent(u)==ds.findUltimateParent(v))
        e++;
        else
        ds.unionByRank(u,v);
      }
      for(int i=0;i<n;i++)
      {
        if(ds.parent[i]==i)
        {
            cc++;
        }
      } 
      if(cc-1<=e)
      {
        return cc-1;
      }
      return -1;
    }
};