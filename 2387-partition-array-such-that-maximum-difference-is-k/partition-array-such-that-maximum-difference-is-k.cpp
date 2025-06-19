class Solution {
public:
    int partitionArray(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        int j=0,cnt=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-nums[j]>k)
            {
              cnt++;
              j=i;
            }
        }
        return cnt;
    }
};