class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int n=nums.size();
    queue<pair<int,int>>q;
    vector<int>ans;
    q.push({0,0});
    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        ans.push_back(nums[i][j]);
        if(!j && i+1<n)
        q.push({i+1,0});
        if(j+1<nums[i].size())
        q.push({i,j+1});
    }
    return ans;
    }
};