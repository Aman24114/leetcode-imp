#define ll long long 
class Solution {
public:
    ll nc2(ll n)
    {
        if(n<2)
        return 0;
        else 
        return n*(n-1)/2;
    }

    int countTrapezoids(vector<vector<int>>& points)
    {
        unordered_map<int,int>mp;
        const int mod=1e9+7;
        for (auto it:points)
        {
            mp[it[1]]++;
        }

        vector<ll>v1;
        for (auto it:mp)
        v1.push_back(it.second);

        vector<ll>v2;
        for (auto it:v1)
        v2.push_back(nc2(it));

        ll sum = accumulate(v2.begin(),v2.end(),0LL);
        ll ans = 0;
        for (int i=0;i<v2.size();i++)
        {
            sum -=v2[i];
            ans +=v2[i]*sum;
            ans %= mod;
        }
        return ans % mod;
    }
};