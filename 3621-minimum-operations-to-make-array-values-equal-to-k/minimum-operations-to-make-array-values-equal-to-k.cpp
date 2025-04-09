class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    set<int>s(nums.begin(),nums.end());
    int m=*min_element(nums.begin(),nums.end());
    if(m<k)
    return -1;
    if(m==k)
    return s.size()-1;
    return s.size();   
    }
};