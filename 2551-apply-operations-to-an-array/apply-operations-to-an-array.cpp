class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
    vector<int>ans;
    int n=nums.size(),z=0;
    for(int i=0;i<n-1;i++)
    {
      if(nums[i]==0)
      {
        z++;
      }
      else if(nums[i]==nums[i+1])
      {
        ans.push_back(nums[i]*2);
        nums[i+1]=0;
      }
      else
      {
        ans.push_back(nums[i]);
      }
    }
    ans.push_back(nums[n-1]);
    for(int i=0;i<z;i++)
    { 
        ans.push_back(0);
    } 
    return ans;
    }
};