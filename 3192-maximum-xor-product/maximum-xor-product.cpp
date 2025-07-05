#define ll long long 
class Solution {
public:
    int mod=1e9+7;
    int maximumXorProduct(ll a, ll b, int n) {
    for(int i=n-1;i>=0;i--)
    {
        bool aset=(a&(1ull<<i));
        bool bset=(b&(1ull<<i));
        if(aset&&bset)
        {
            continue;
        }
        if(!aset && !bset)
        {
            a^=(1ull << i);
            b^=(1ull << i);
        }
        if(aset)
        {
            if(a>b)
            {
                a^=(1ull << i);
                b^=(1ull << i);
            }
        }
        if(bset)
        {
            if(b>a)
            {
                a^=(1ull << i);
                b^=(1ull << i);
            }
        }
    }
     return ((a%mod)*(b%mod))%mod;
    }
};