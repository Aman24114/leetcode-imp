class Solution {
public:
    int maxSum(vector<int>& nums) {
    bool b=true;
    int maxi=INT_MIN;
    for(auto it:nums)
    {
       if(it>0) b=false;
       if(it>maxi) maxi=it;
    } 
    if(b==true)
    return maxi;  
    unordered_set<int>st(nums.begin(),nums.end());
    int sum=0;
    for(auto it:st)
    {
      if(it>0)
      {
        sum+=it;
      }
    }
    return sum;
    }
};