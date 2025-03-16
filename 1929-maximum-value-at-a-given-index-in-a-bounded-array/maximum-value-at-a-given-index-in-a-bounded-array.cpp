#define ll long long 
class Solution {
public:
    ll f(ll cnt, ll x)
    {
        return cnt*x - cnt*(cnt+1)/2;
    }
    int maxValue(int n, int index, int maxSum) {
    ll l=1;
    ll r= maxSum;
    ll mid=0;
    ll ans=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        ll lcnt= min((ll)index,mid-1);
        ll lsum= f(lcnt,mid);
        lsum+=max((ll)0,index-lcnt);

        ll rcnt= min((ll)n-index-1,mid-1);
        ll rsum= f(rcnt,mid);
        rsum+=max((ll)0,(n-index-1)-rcnt);
        
        ll tsum= lsum+mid+rsum;
        if(tsum<=maxSum)
        {
           ans= max(ans,mid);
           l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
    }
};