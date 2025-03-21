#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
    int n=nums.size();
    if(k==0)
    return nums;
    vector<int>result(n,-1);
    if(n<2*k+1)
    return result;
    ll w=0;
    int l=0,r=2*k;
    int i=k;
    for(int i=l;i<=r;i++)  
    {
        w+=nums[i];
    }     
    result[i]=w/(2*k+1);
    i++;
    r++;
    while(r<n)
    {
        int l1=nums[l];
        int r1=nums[r];
        w+=(r1-l1);
        result[i]=w/(2*k+1);
        i++;
        l++;
        r++;
    }
    return result;
    }
};