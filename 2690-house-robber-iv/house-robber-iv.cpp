// mamximize on mimiimum 
// ya minimize on maximimum --binary search lagega
// always possible hoga to steal from k houses
// agar nahing hoga toh greedily bhi nahin hoga
class Solution {
public:
    bool f(vector<int>&nums,int mid,int k)
    {
        int h=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            {
                h++;
                i++;
            }
        }
        return h>=k;
    }
    int minCapability(vector<int>& nums, int k) {
    int l=*min_element(nums.begin(),nums.end());
    int r=*max_element(nums.begin(),nums.end());
    int ans=r;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(f(nums,mid,k)==true)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;   
    }
};