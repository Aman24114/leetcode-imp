class Solution {
public:
    int findMin(vector<int>& nums) {
    int l=0,h=nums.size()-1;
    int m=5000;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(nums[l]==nums[h])
        {
            m=min(m,nums[l]);
            l++;
            h--;
            continue;
        }
        if(nums[l]<=nums[mid])
        {
            m=min(m,nums[l]);
            l=mid+1;
        }
        else 
        {
            m=min(nums[mid],m);
            h=mid-1;
        }
    }
    return m;
    }
};