#define ll long long 
class Solution {
public:
    ll countInterestingSubarrays(vector<int>& nums, int modulo, int k)
    {
    ll cnt = 0, pre = 0;
    unordered_map<int ,ll> mp;
    mp[0] = 1;
    for (auto it :nums)
    {
        if (it % modulo == k) pre++;
        int rem = pre % modulo;
        int req = (rem - k + modulo) % modulo;
        cnt += mp[req];
        mp[rem]++;
    }
    return cnt;
    }
};