class Solution {
public:
    int f(int n)
    {
        int cnt=0;
        int sum=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cnt++;
                sum+=i;
                if(i!=n/i)
                {
                    cnt++;
                    sum+=n/i;
                }
            }
        }   
        if(cnt==4)
        return sum;
        else 
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        int n=nums[i];
        ans+=f(n);
    }   
    return ans;
    }
};