#define ll long long
class Solution {
public:
    ll getDescentPeriods(vector<int>& prices) {
    ll ans=1;ll cnt=1;
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]==prices[i-1]-1)
        cnt++;
        else 
        cnt=1;
        ans+=cnt;
    }
    return ans;
    }
};