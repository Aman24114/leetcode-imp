class Solution {
public:
    void f(vector<int>&nums,vector<vector<int>>&ans,int ind)
    {
        int n=nums.size();
        if(ind>=n-1)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            f(nums,ans,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>>ans;
    f(nums,ans,0);
    set<vector<int>>st(ans.begin(),ans.end());
    ans.clear();
    for(auto it:st)
    {
        ans.push_back(it);
    }
    return ans;
    }
};