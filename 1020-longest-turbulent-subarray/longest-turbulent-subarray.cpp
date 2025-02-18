class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
        return 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1]=(arr[0] == arr[1]) ? 1 : 2; 
        int maxi = dp[1];
        for (int i = 2; i < n; i++) {
            if ((arr[i-2] < arr[i-1] && arr[i-1] > arr[i]) ||(arr[i-2] > arr[i-1] && arr[i-1] < arr[i])) {
                dp[i] = dp[i-1] + 1;
            }
            else
            {
            dp[i] = (arr[i] == arr[i-1]) ? 1 : 2;
            }
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
    }
};
