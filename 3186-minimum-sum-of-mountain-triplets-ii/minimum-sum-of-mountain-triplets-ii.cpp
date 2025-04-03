class Solution {
public:
    int minimumSum(vector<int>& nums) {
    int n=nums.size();
    vector<int>premin(n);
    vector<int>postmin(n);
    premin[0]=nums[0];
    postmin[n-1]=nums[n-1];
    for(int i=1;i<n;i++)
    {
        premin[i]=min(premin[i-1],nums[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        postmin[i]=min(postmin[i+1],nums[i]);
    }
    int ans=INT_MAX;
    for(int i=1;i<n-1;i++)
    {
        if(premin[i-1]<nums[i] && nums[i]>postmin[i+1])
        {
          ans=min(ans,nums[i]+postmin[i+1]+premin[i-1]);   
        }
    }
    return ans==INT_MAX? -1:ans;
    }
};