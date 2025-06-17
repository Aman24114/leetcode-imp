#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
 
    int f1(int a,int b)
    { 
        int ans = 1;
        while(b)
        {
            if(b%2)
            {
                ans = (1LL*a*ans)%mod;
            }
            b = b/2;
            a = (1LL*a*a)%mod;
        }
        return ans;
    }
    int f2(int n,int r)
    {
        r = min(r,n-r);
        int ans = 1;
        int rfac = 1;
        for(int i = 0;i<r;i++)
        {
            ans = (1LL*ans*(n-i))%mod;
            rfac = (1LL*rfac*(i+1))%mod;
        }
        ans = (1LL * ans * f1(rfac,mod-2))%mod;
        return ans;
    }
    int countGoodArrays(int n, int m, int k)
    {
        int ans = m;
        ans = (1LL*ans*f1(m-1,n-k-1))%mod;
        ans = (1LL*ans*f2(n-1,k))%mod;
        return ans;
    }
};