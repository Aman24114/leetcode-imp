class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
    int i=0,j=0;
    int ans=1,initial=0;
    while(j<nums.size())
    {
    while((initial & nums[j])!=0)
    {
        initial^=nums[i];
        i++;
    }
    ans=max(ans,j-i+1);
    initial|=nums[j];
    j++;
    }
    return ans;
    }
};