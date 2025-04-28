#define ll long long
class Solution {
public:

    ll countSubarrays(vector<int>& nums, ll  k)
    {
      ll sum=0,ans=0,score;
      int l=0;
      int n=nums.size();
      for(int r=0;r<n;r++)
      {
        sum+=nums[r];
        while(l<=r && sum*(r-l+1)>=k)
        {
            sum-=nums[l];
            l++;
        }
        ans+=(r-l+1);
      } 
      return ans;
    }
};