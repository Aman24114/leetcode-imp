#define ll long long 
class Solution {
public:
    ll maximumTripletValue(vector<int>& nums) {
    int n=nums.size();
    if(n<3)
    return 0;
    ll maxr=0;
    ll maxi=nums[0];
    ll maxdif=0;
    for(int i=1;i<n;i++)
    {
        maxr=max(maxr,(ll)maxdif*nums[i]);
        maxdif=max(maxdif,(ll)maxi-nums[i]);
        maxi= max(maxi,(ll)nums[i]);
    } 
    return maxr;  
    }
};