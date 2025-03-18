#define ll long long 
class Solution {
public:
    ll countSubarrays(vector<int>& nums, int k) {
    int maxnum=*max_element(nums.begin(),nums.end());
    int n=nums.size();int i=0,j=0;
    ll ans=0;
    int cnt=0;
    while(j<n)
    {
        if(nums[j]==maxnum)
        {
            cnt++;
        }
        while(cnt>=k)
        {
        ans+=n-j;
        if(nums[i]==maxnum)
        {
            cnt--;
        }
        i++;
        }
        j++;
    }
    return ans;     
    }
};