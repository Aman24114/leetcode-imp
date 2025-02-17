class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)   
    {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     vector<int>dp(n,1);
     vector<int>hash(n,-1);
     for(int i=0;i<n;i++)
     {
        hash[i]=i;
       for(int prev=0;prev<i;prev++)
       {
        if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
        {
            dp[i]=1+dp[prev];
            hash[i]=prev;
        }
       }
     }
     int ans=-1;
     int lastindex=-1;
     for(int i=0;i<n;i++)
     {
        if(dp[i]>ans)
        {
            ans=dp[i];
            lastindex=i;
        }
     }
     vector<int>temp;
     temp.push_back(nums[lastindex]);
     while(hash[lastindex]!=lastindex)
     {
       lastindex=hash[lastindex];
       temp.push_back(nums[lastindex]); 
     }
     reverse(temp.begin(),temp.end());
     return temp;
    }
};