#define ll long long
class Solution {
public:
    bool f(vector<int>&nums,int mid,int n)
    {
        vector<ll>v(begin(nums),end(nums));
        for(int i=0;i<n-1;i++)
        {
            if(v[i]>mid)
            {
                return false;
            }
            ll rem=mid-v[i];
            v[i+1]-=rem;
        }
        return v[n-1]<=mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
    int n=nums.size();
    int l=0;
    int r= *max_element(nums.begin(),nums.end());
    int ans=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(f(nums,mid,n))
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