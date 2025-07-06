class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    int xor1=0;
    for(auto &it:nums)
    {
        xor1^=it;
    }  
    int bitstobedifferent=xor1^k;
    int totalbitstobechanged=__builtin_popcount(bitstobedifferent);
    return totalbitstobechanged;
    }
};