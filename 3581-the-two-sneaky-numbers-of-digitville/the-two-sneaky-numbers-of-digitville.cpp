class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
    vector<bool>b(nums.size(),0);
    vector<int>ans;
    for(auto it:nums)
    {
        if(b[it])
        ans.push_back(it);
        else 
        b[it]=1;
    }   
    return ans;
    }
};