#define ll long long
class Solution {
public:
    bool f(vector<int>&b,ll mid, int n)
    {
        ll reqmin=(ll)n*mid;
        ll sum=0;
        for(int i=0;i<b.size();i++)
        {
            sum+=min((ll)b[i],mid);
            if(sum>=reqmin)
            {
                return true;
            }
        }
        return false;
    }
    ll maxRunTime(int n, vector<int>& b) {
    ll l= *min_element(b.begin(),b.end());
    ll minut=0;
    for(int it:b)
    {
        minut+=it;
    } 
    ll r= minut/n;
    ll ans=0;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(f(b,mid,n))
        {   ans=mid;
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