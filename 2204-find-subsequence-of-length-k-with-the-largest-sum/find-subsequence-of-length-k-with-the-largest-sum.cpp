class Solution {
public:
    typedef pair<int,int>P;
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<P>pq;
    for(int i=0;i<nums.size();i++)
    {
        pq.push({nums[i],i});
    }
    vector<P>v;
    while(k--)
    {
        auto it=pq.top();
        int num=it.first;
        int idx=it.second;
        pq.pop();
        v.push_back({idx,num});
    }
    sort(v.begin(),v.end());
    vector<int>ans;
    for(auto &it:v)
    {
        ans.push_back(it.second);
    }
    return ans;
    }
};