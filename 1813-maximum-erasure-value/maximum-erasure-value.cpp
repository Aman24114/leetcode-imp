class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
     // return  the maximum score you can get by erasing exactly one subarray
     int maxi=0;int j=0; int n=arr.size();int req;int sum=0;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++)
     {
         mp[arr[i]]++;
         sum+=arr[i];
         while(mp[arr[i]]>1)
         {
             sum-=arr[j];
             --mp[arr[j]];
             j++;
         }
          maxi=max(sum,maxi);  
     }
     return maxi;
     
    }
};