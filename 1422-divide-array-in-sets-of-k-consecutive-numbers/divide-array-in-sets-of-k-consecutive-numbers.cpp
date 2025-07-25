class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>pq;
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]]++;
    }    
    for(auto it:mp)
    {
        pq.push(it.first);
    }
    while(!pq.empty())
    {
        auto it=pq.top();
        for(int i=it;i<it+k;i++)
        {
            if(mp[i]==0)
            return false;
            else 
            {
                mp[i]--;
            }
            while(!pq.empty()&& mp[pq.top()]==0)
            {
                pq.pop();
            }
        }
    }
    return true;
    }
};