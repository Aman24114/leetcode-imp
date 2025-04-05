class Solution {
public:
    int f(int i,int sum,vector<int>&nums)
    {
        if(i==nums.size())
        return sum;
        int t=f(i+1,sum^nums[i],nums);
        int nt=f(i+1,sum,nums);
        return t+nt;
    }
    int subsetXORSum(vector<int>& nums) {
    int n=nums.size();
    return f(0,0,nums);    
    }
};