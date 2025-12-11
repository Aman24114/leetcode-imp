#define ll long long 
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {
    vector<ll>psum(k,LLONG_MAX);
    ll prefix=0;
    ll ans=LLONG_MIN;
    psum[0]=0;
    for(int i=0;i<nums.size();i++)
    {
        prefix+=nums[i];
        int mod=(i+1)%k;
        if(psum[mod]!=LLONG_MAX)
        {
            ans=max(ans,prefix-psum[mod]);
        }
        psum[mod]=min(psum[mod],prefix);
    }
    return ans;
    }
};