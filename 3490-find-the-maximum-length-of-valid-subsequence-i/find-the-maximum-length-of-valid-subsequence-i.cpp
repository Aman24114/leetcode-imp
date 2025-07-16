class Solution {
public:
    int maximumLength(vector<int>& nums) {
    int o=0,e=0;
    int cnt=0;
    bool flag=nums[0]%2==1;

    for(auto it:nums)
    {
       if(it%2==1)
       {
         if(flag)
         {
           flag=!flag;
           cnt++;
         }
         o++;
       }
       else 
       {
         if(!flag)
         {
           flag=!flag;
           cnt++;
         }
         e++;
       }
    }
    return max({cnt,o,e});
    }
};