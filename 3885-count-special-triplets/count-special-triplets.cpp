#define ll long long 
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
    ll mod=1e9+7;
    unordered_map<int,int>r,l;
    for(auto it:nums)
    {
        r[it]++;
    }   
    ll ans=0;
    for(int j=0;j<nums.size();j++){
    int m=nums[j];
    r[m]--;
    ll req=m*2LL;
    ans=(ans+((l[req])%mod*(r[req]%mod)%mod))%mod;
    l[m]++;
    }
    return (int)ans;
    }
};