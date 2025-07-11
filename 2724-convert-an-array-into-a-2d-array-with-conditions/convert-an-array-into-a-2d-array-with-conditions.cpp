class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>>ans;
    unordered_set<int>st;
    while(!nums.empty())
    {
        vector<int>row;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])==st.end())
            {
                st.insert(nums[i]);
                row.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        ans.push_back(row);
        st.clear();
    }
    return ans;
    }
};