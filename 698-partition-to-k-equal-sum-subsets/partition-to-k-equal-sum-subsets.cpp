class Solution {
public:
 bool f(vector<int>&nums,int curr,int sum,int k,int start,vector<bool>&vis)
{
        if(k==1)
            return true;
        if(start>=nums.size())
           return false;
        if(curr==sum)
                return f(nums,0,sum,k-1,0,vis);
    
    for(int i=start;i<nums.size();i++)
    {
        if(vis[i] || nums[i]+curr>sum)
            continue;
        vis[i]=true;
        if(f(nums,curr+nums[i],sum,k,i+1,vis))
            return true;
        vis[i]=false;
    }
    return false;
}
   bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto x:nums) sum+=x;
        vector<bool>vis(nums.size(),false);
         if(sum%k!=0)
        return false;
        int s=sum/k;
         sort(begin(nums),end(nums),greater<int>());
        return f(nums,0,s,k,0,vis);
  }
};
