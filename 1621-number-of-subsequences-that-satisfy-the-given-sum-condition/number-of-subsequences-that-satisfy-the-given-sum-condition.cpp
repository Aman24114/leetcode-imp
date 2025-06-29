#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int f(int b1,int exp)
    {
        ll ans=1;
        ll b=b1;
        while(exp>0)
        {
            if(exp%2==1)
            {
                ans=(ans*b)%mod;
            }
            b=(b*b)%mod;
            exp/=2;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int t) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int i=0, j=n-1;
    int ct=0;
    while(i<=j)
    {
        if(nums[i]+nums[j]<=t)
        {
            ct=(ct+f(2,j-i))%mod;
            i++;
        }
        else
        {
            j--;
        }
    }
    return ct;
    }
};