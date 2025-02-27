class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        if (arr.size() <= 2) return 0;
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = arr[j];
                int p1 = arr[i];
                int len = 2;
                while (mp.find(p+ p1) != mp.end()) {
                    len++;
                    maxi = max(maxi, len);
                    int x = p;
                    p = p + p1;
                    p1 = x;
                }
            }
        }

        return maxi > 2 ? maxi:0;
    }
};