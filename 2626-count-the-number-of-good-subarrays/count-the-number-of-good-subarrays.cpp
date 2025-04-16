#define ll long long
class Solution {
public:
    ll countGood(vector<int>& nums, int k)
     {
      int n=nums.size();
      int i=0,j=0;
      ll result=0;
      ll pairs=0;
      unordered_map<int,int>mp;
      while(j<n)
      {
       pairs+=mp[nums[j]];
       mp[nums[j]]++;
       while(pairs>=k)
       {
        result+=(n-j);
        mp[nums[i]]--;
        pairs-=mp[nums[i]];
        i++;
       }
       j++;
     } 
     return result; 
    }
};