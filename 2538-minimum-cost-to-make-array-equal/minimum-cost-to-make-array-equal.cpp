#define ll long long 
class Solution {
public:
    ll f(vector<int>&nums,vector<int>&cost,int k)
    {
        ll ans1=0;
        for(int i=0;i<nums.size();i++)
        {
            ans1+= (ll)abs(nums[i]-k)*cost[i];
        }
        return ans1;
    }
    ll minCost(vector<int>& nums, vector<int>& cost) {
    ll ans = INT_MAX;
    int l= *min_element(nums.begin(),nums.end());
    int r = *max_element(nums.begin(),nums.end());
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        ll c1= f(nums,cost,mid);
        ll c2= f(nums,cost,mid+1);
        ans=min(c1,c2);
        if(c2>c1)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans==INT_MAX ? 0:ans;
    }
};