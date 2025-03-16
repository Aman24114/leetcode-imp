#define ll long long
class Solution {
public:
    bool f(vector<int>&ranks,ll mid,int cars)
    {
        ll ca=0;
        for(int i=0;i<ranks.size();i++)
        {
           ca+= sqrt((double)mid/ranks[i]);
           if(ca>=cars)
           return true;
        }
        return ca>=cars;
    }
    ll repairCars(vector<int>& ranks, int cars) {
    ll l = 1;
    int rank= *max_element(ranks.begin(),ranks.end());
    ll r=  1LL*rank*cars*cars;
    ll ans=-1;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(f(ranks,mid,cars))
        {
          ans=mid;
          r=mid-1;   
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
    }
};