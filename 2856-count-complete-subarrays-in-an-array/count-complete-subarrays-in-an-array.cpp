class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int>mp;
    unordered_set<int>st(nums.begin(),nums.end());
    int dig=st.size();
    int ans=0;
    int l=0;
    for(int r=0;r<n;r++)
    {
        mp[nums[r]]++;
        while(l<=r && mp.size()==dig)
        {
            ans+=nums.size()-r;
            mp[nums[l]]--;
            if(mp[nums[l]]==0)
            mp.erase(nums[l]);
            l++;
        }
    }
    return ans; 
    }
};