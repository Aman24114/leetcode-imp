class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN, mini=INT_MAX;
        int c1=0,c2=0;
        for (int n:nums) {
            c1+= n;
            c2 += n;
            maxi= max(c1, maxi);
            mini= min(c2, mini);
            if (c1 < 0) c1 = 0;
            if (c2 > 0) c2 = 0;
        }
        return max(abs(mini), maxi);
    }
};