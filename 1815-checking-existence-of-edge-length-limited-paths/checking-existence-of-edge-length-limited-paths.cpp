class DSU {
    vector<int> parent, rank, size;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int x1 = find(x);
        int y1 = find(y);
        if (x1 == y1) return;

        if (rank[x1] > rank[y1]) {
            parent[y1] = x1;
            size[x1] += size[y1];
        } else if (rank[x1] < rank[y1]) {
            parent[x1] = y1;
            size[y1] += size[x1];
        } else {
            parent[y1] = x1;
            rank[x1]++;
            size[x1] += size[y1];
        }
    }   bool sameparent(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        DSU dsu(n);
        int m = e.size();
        int k = q.size();

        for (int i = 0; i < k; i++) {
            q[i].emplace_back(i); 
        }
        sort(q.begin(), q.end(), comp);
        sort(e.begin(), e.end(), comp);

        int i = 0;
        vector<bool> result(k);
        for (const vector<int>& query : q) {
            while (i < m && e[i][2] < query[2]) {
                dsu.unite(e[i][0], e[i][1]);
                i++;
            }
            result[query[3]] = dsu.sameparent(query[0], query[1]);
        }
        return result;
    }
};
