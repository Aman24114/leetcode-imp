class Solution {
public:
    int minSwaps(vector<int>& nums) {
    int n=nums.size();
    int onecnt = accumulate(nums.begin(), nums.end(), 0);
    if(onecnt==0)
    return 0;
    int i=0,j=0;
    int currone=0;
    int maxi=0;
    while(j<2*n)
    {
        if(nums[j%n]==1)
        {
            currone++;
        }
        if(j-i+1>onecnt)
        {
            currone-=nums[i%n];
            i++;
        }
        maxi=max(maxi,currone);
        j++;
    }
    return onecnt-maxi;
    }
};