class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int i=0,j=0;
    int p=1,cnt=0;
    int n=nums.size();
    if(k<=1)
    return 0;
    while(j<n)
    {
        p*=nums[j];
        while(p>=k)
        {
            p/=nums[i];
            i++;
        }
        cnt+=j-i+1;
        j++;
    }    
    return cnt;
    }
};