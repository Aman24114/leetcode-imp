#define ll long long
class Solution {
public:
    bool f(vector<int>&can,int mid,ll k)
    {
        ll cnt=0;
        for(int i=0;i<can.size();i++)
        {
            cnt+=can[i]/mid;
            if(cnt>=k)
            {
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& can, ll k) {
    int n=can.size();
    int maxi=*max_element(can.begin(),can.end()); 
    int l=1;
    int r=maxi;
    int result=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(f(can,mid,k))
        {
            result=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return result;
    }
};