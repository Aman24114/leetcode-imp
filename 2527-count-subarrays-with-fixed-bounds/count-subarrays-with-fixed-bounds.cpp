#define ll long long
class Solution {
public:
    ll countSubarrays(vector<int>& nums, int mink, int maxk)
    {  
       ll n=nums.size();
       ll cnt=0,s=-1,mini=-1,maxi=-1;
       for(int i=0;i<n;i++)
       {
          if(nums[i]<mink || nums[i]>maxk)
          s=i;
          if(nums[i]==maxk)
          maxi=i;
          if(nums[i]==mink)
          mini=i;
          int validsubarray=max(0LL,min(mini,maxi)-s);
          cnt+=validsubarray;
       } 
       return cnt;   
    }
};