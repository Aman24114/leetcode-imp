class Solution {
public:
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};
    int minTimeToReach(vector<vector<int>>& mt)
    {
        int n = mt.size();
        int m = mt[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int t = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (row == n - 1 && col == m - 1)
            {
                return t;
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int dif = max(t, mt[nr][nc])+1;
                    if (dif < dis[nr][nc])
                    {
                        dis[nr][nc] = dif;
                        pq.push({dif, {nr, nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};