class Solution {
public:
    int findLHS(vector<int>& nums) {
    int maxi=0;
    unordered_map<int,int>mp;
    for(auto it:nums)
    {
        mp[it]++;
    }  
    for(auto it:mp)
    {
        int num=it.first;
        int cnt=it.second;
        if(mp.find(num+1)!=mp.end())
        {
            int len=cnt+mp[num+1];
            maxi=max(maxi,len);
        }
    }
    return maxi;
    }
};