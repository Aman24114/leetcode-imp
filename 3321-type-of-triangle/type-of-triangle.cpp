class Solution {
public:
    string triangleType(vector<int>& nums)
    {
    sort(nums.begin(),nums.end());
    bool b=(((nums[0]+nums[1])>nums[2])&&((nums[1]+nums[2])>nums[0])&&((nums[0]+nums[2])>nums[1]));
    if(!b)
    return "none";
    if(nums[0]==nums[1]&& nums[2]==nums[1]&& nums[0]==nums[2])
    return "equilateral";
    if(nums[0]!=nums[1]&& nums[1]!=nums[2]&& nums[2]!=nums[0])
    return "scalene";
    else
    return "isosceles";
    }
};