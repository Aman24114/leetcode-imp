// dp[i] = length of lds
// v[i]=last divisble wla number
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)   
    {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     vector<int>dp(n,1);
     vector<int>v(n,-1);
     for(int i=0;i<n;i++)
     {
       v[i]=i;
       for(int prev=0;prev<i;prev++)
       {
        if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
        {
            dp[i]=1+dp[prev];
            v[i]=prev;
        }
       }
     }
     int ans=-1,lastidx=-1;
     for(int i=0;i<n;i++)
     {
        if(dp[i]>ans)
        {
            ans=dp[i];
            lastidx=i;
        }
     }
     vector<int>temp;
     temp.push_back(nums[lastidx]);
     while(v[lastidx]!=lastidx)
     {
       lastidx=v[lastidx];
       temp.push_back(nums[lastidx]); 
     }
     reverse(temp.begin(),temp.end());
     return temp;
    }
};