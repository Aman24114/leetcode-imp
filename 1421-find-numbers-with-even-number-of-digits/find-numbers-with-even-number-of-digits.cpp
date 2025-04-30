class Solution {
public:
    bool f(int num)
    {   int n=0;
        while(num)
        {
           n++;
           num=num/10;
        }
        if(n%2==0)
        {
            return true;
        }
        return false;
    }
    int findNumbers(vector<int>& nums) {
    int n=nums.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int n1=0;
        int num=nums[i];
        if(f(num))
        {
            ans++;
        }
    } 
    return ans;
    }
};