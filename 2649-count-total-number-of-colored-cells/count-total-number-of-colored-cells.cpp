#define ll long long 
class Solution {
public:
    long long coloredCells(int n) {
    int t=1;
    ll ans=1;
    while(t<=n)
    {
        ans+=(4*(t-1));
        t++;
    }  
    return ans;
    }
};