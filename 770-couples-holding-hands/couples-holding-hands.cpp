class DisjointSet {
public: 
    vector<int> parent, size; 
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findupar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findupar(parent[node]);
    }

    void unionbysize(int u, int v) {
        int upu = findupar(u);
        int upv = findupar(v);
        if (upu == upv) return;
        if (size[upu] <size[upv]) {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
}; 

class Solution
{
public:
int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int n = row.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i+=2) {
            ds.unionbysize(i,i+1);
        }
        for (int i = 0; i < n; i += 2) {
            int a=ds.findupar(row[i]);
            int b=ds.findupar(row[i+1]);
            if(a!=b){
                ds.unionbysize(a,b);
                ans++;
            }
        }

        return ans;
    }
};