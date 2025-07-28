class Solution {
public:
    int f(int i,vector<int>&nums,int maxi,int curor)
    {
        if(i>=nums.size())
        {
            return curor == maxi ? 1:0;
        }
        int t=f(i+1,nums,maxi,curor|nums[i]);
        int nt=f(i+1,nums,maxi,curor);
        return t+nt;
    }
    int countMaxOrSubsets(vector<int>& nums) {
    int maxi=0;
    for(int num:nums)
    {
        maxi|=num;
    }
    return f(0,nums,maxi,0);
    }
};