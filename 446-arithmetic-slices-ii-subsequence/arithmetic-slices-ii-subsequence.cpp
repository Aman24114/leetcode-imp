class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<long long, long long>> mp(n); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - (long long)nums[j]; 
                int count = mp[j].count(diff) ? mp[j][diff] : 0;
                mp[i][diff] += count + 1;
                ans += count;
            }
        }
        return ans;
    }
};

