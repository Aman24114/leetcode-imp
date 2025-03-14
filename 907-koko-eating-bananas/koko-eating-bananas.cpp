#define ll long long 
class Solution {
public:
    ll f(vector<int>&piles,int mid1)
    {
        ll t=0;
        for(int i=0;i<piles.size();i++)
        {
           int t1=ceil(piles[i]/(double)mid1);
           t+=t1;
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    int l=1;
    int r=*(max_element(piles.begin(),piles.end()));
    int ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        ll k=f(piles,mid);
        if(k<=h)
        {
            ans=mid;
            r=mid-1;
        }
        else
        l=mid+1;
    } 
    return ans;  
    }
};