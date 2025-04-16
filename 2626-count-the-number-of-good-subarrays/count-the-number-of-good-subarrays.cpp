#define ll long long 
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
    int n=nums.size();
    ll ans=0;
    unordered_map<int,int>mp;
    ll pairs=0;
    ll l=0,r=-1;
    while(l<n || r+1<n)
    {
        while(r+1<n && pairs<k)
        {
            r++;
            mp[nums[r]]++;
            if(mp[nums[r]]>1)
            {
                pairs+=mp[nums[r]]-1; // kitna pair banega
            }
        }
        if(pairs>=k)
        {
            ans+=(n-r);// n-r tak ka subarray phir slngidn window lagake shift karenge
        }
        mp[nums[l]]--;
        pairs-=mp[nums[l]];
        l++;
    } 
    return ans;   
    }
};