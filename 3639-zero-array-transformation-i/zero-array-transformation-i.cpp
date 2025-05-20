class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    { 
       int n=nums.size();
       vector<int>diff(n,0);
       for(auto it:queries)
       {
         int s=it[0];
         int e=it[1];
         diff[s]+=1;
         if(e+1<n)
         diff[e+1]-=1;
       } 
       vector<int>v(n,0);
       int sum=0;
       for(int i=0;i<n;i++)
       {
         sum+=diff[i];
         v[i]=sum;
       }  
       for(int i=0;i<n;i++)
       {
         if(v[i]<nums[i])
         {
            return false;
         }
       }
       return true;
    }
};