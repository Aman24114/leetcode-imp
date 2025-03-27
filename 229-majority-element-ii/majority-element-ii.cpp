class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    int cnt1,cnt2=0;
    int maxi1,maxi2=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==maxi1)
        {
            cnt1++;
        }
       else if(nums[i]==maxi2)
        {
            cnt2++;
        }
        else if(cnt1==0)
        {
            maxi1=nums[i];
            cnt1=1;
        }
        else if(cnt2==0)
        {
            maxi2=nums[i];
            cnt2=1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
      // verify karenge
      vector<int>ans;
      int f1=0,f2=0;
      for(auto &it:nums)
      {
        if(it==maxi1)
        {
            f1++;
        }
        if(it==maxi2)
        {
            f2++;
        }
      }
      if(f1>n/3)
      {
        ans.push_back(maxi1);
      }
      if(f2>n/3)
      {
        ans.push_back(maxi2);
      }
     return ans;
    }
};