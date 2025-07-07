class Solution {
typedef long long ll;
public:
    int countNicePairs(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int n=nums[i];
        int rev=0;
        while(n!=0)
        {
            rev*=10;
            rev+=n%10;
            n/=10;
        }
        nums[i]-=rev;
        mp[nums[i]]++;
    }  
    ll cnt=0;
    ll mod=1e9+7;
    for(auto &it:mp)
    {
       ll freq=it.second;
       cnt=(cnt+((freq*(freq-1))/2)%mod)%mod;
    }
    return cnt;
    }
};