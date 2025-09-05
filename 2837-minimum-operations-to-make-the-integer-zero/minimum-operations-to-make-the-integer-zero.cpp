#define ll long long 
class Solution {
public:
    int f(ll num){
    int ans = 0;
    while (num>0)
    {
        if (num%2)
        ++ans;
        num/=2;
    }
    return ans;
    }
    int makeTheIntegerZero(int num1, int num2) {
    int ans = 1;
    ll t = num1-num2;
    while(t>0) 
    {
        if (f(t)==ans)
        return ans;
        if (f(t)<=ans && t>=ans) 
        return ans;
        ++ans;
        t -= num2;
    }
    return -1;
    }
};