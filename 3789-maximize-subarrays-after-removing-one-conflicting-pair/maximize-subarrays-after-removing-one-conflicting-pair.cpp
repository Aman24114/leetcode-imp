class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> c(n + 1);
        for (const auto&pair : conflictingPairs)
        {
            int u = pair[0], v = pair[1];
            c[max(u, v)].push_back(min(u, v));
        }
        long long res = 0;
        int max_diff = 0, max_left = 0;
        vector<long long> prefix(n + 1, 0);
        for (int r = 1; r <= n; r++){
            for (int l :c[r]){
                if (l > max_diff){
                    int temp = max_diff;
                    max_diff = l;
                    max_left = temp;
                } else if ( l > max_left){
                    max_left = l;
                }
            }
            res += r - max_diff;
            if (max_diff > 0){
                prefix[max_diff] += max_diff - max_left;
            }
        }
        return res + *max_element(prefix.begin(), prefix.end());
    }
};