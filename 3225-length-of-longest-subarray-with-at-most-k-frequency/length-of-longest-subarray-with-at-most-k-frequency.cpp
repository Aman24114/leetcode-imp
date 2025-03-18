class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    int n=nums.size();
    unordered_map<int,int>mp;
    int i=0,j=0;
    int ans=0;
    int dikkatno=0;
    while(j<n)
    {
        mp[nums[j]]++;
        if(mp[nums[j]]==k+1)
        {
            dikkatno++;
        }
        while (dikkatno > 0) 
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == k)
            {
                dikkatno--;
            }
            i++;
        }
        if(dikkatno ==0)
        {
            ans=max(ans,j-i+1);
        }
        j++;
    }
    return ans;
    }
};