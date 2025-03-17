#define ll long long
class Solution {
public:
    bool f(vector<int>&nums,int mid,int maxo)
    {
        ll totalop=0;
        for(int &n:nums)
        {  ll op=(ll)n/(ll)mid;
           if(n%mid==0)
           {
            op-=1;
           }
           totalop+=op;
        }
        return totalop<=(ll)maxo;
    }
    int minimumSize(vector<int>& nums, int maxo) {
    int ans=0;
    int l=1;
    int r=*max_element(nums.begin(),nums.end());
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(f(nums,mid,maxo))
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