class Solution {
public:
    int sumOfBeauties(vector<int>& nums)
    {  int n=nums.size();
       vector<int>postmin(n);
       vector<int>premax(n);
       premax[0]=nums[0];
       for(int i=1;i<n;i++)
       {
          premax[i]=max(premax[i-1],nums[i]);
       }
        postmin[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--)
       {
        postmin[i]=min(postmin[i+1],nums[i]);
       }
       int cnt=0;
       for(int i=1;i<n-1;i++)
       {
        if(premax[i-1]<nums[i] && nums[i]<postmin[i+1])
        {
          cnt+=2;
        }
        else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
        {
            cnt++;
        }
       }
       return cnt;
    }
};