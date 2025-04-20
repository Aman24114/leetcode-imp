class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
    int ans=1;
    int n=nums.size();
    int b=nums[0];
    for(int i=1;i<n;i++)
    {
        if(b<=nums[i])
        {
            ans++;
            b=nums[i];
        }
    } 
    return ans; 
    }
};