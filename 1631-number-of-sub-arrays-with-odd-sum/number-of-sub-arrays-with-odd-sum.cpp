#define ll long long 
class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
    ll sum=0;
    ll ans=0;
    int odd=0,even=1;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        if(sum %2==1)
        {
            odd++;
            ans+=even;
        }
        else
        {
            even++;
            ans+=odd;
        }
    } 
    return ans%mod;  
    }
};