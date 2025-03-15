#define ll long long
class Solution {
public:
    bool f(vector<int>time,int tt,ll mid)
    {
        ll t1=0;
        for(int i=0;i<time.size();i++)
        {
            t1+=(mid/time[i]);
        }
        return t1>=tt;
    }
    ll minimumTime(vector<int>& time, int tt) {
    ll l=1;
    ll r = (ll)*min_element(time.begin(),time.end())*tt;
    while(l<r)
    {
        ll mid=l+(r-l)/2;
        if(f(time,tt,mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r;
    }
};