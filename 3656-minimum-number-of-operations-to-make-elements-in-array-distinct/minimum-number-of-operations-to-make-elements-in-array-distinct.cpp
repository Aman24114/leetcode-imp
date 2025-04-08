class Solution {
public:
    int minimumOperations(vector<int>& nums) {
    int ans=0;
    int n;
    unordered_map<int,int>mp;
    while(!false)
    {   
        mp.clear();
        bool b=false;
        for(int it:nums)
        {
            mp[it]++;
            if(mp[it]>1)
            b=true;
        }
        if(!b)
        break;
        n=nums.size();
        int rem=min(3,n);
        nums.erase(nums.begin(),nums.begin()+rem);
        ans++;
    }
    return ans;
    }
};