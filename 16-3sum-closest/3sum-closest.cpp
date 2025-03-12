class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
    sort(nums.begin(),nums.end());  
    int nextsum=INT_MAX/2;
    for(int i=0;i<nums.size()-2;i++)
    {
        int l=i+1;int r=nums.size()-1;
        while(l<r)
        {
          int curr=nums[i]+nums[l]+nums[r];
          if( abs(curr-t)< abs(nextsum-t))
          {
            nextsum=curr;
          }
          if(curr<t)
          {
            ++l;
          }
          else if(curr>t)
          {
            --r;
          }
          else
          {
            return curr;
          }
        }
    }
    return nextsum;
    }
};