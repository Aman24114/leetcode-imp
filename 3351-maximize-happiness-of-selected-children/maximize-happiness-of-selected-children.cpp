#define ll long long 
class Solution {
public:
    ll maximumHappinessSum(vector<int>& h, int k) {
    int n=h.size(),cnt=0;
    sort(h.begin(),h.end());
    ll ans=0;
    for(int i=n-1;i>=n-k;i--)
    {
      if(h[i]-cnt>0)
      {
        ans+=(ll)(h[i]-cnt);
      }
      cnt++;
    } 
    return ans;
    }
};