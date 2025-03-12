class Solution {
public:
    int f(vector<int>&nums,int t)
    {
      int l=0;int r=nums.size()-1;int ans=nums.size();
      while(l<=r)
      {
        int mid=(l+(r-l)/2);
        if(nums[mid]<t)
        {
          l=mid+1;
        }
        else
        {
            ans=mid;
            r=mid-1;
        }
      }
      return ans; 
    }
    int maximumCount(vector<int>& nums) {
    int c1= f(nums,0);
    int c2=nums.size()-f(nums,1);
    return max(c1,c2);   
    }
};