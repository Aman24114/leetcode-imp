class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    if(n==0)
    return 1;
    if(n==1)
    return 10;
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=10;
    int a=9,b=9;
    for(int i=2;i<=n;i++)
    {
       a=a*b;
       dp[i]=dp[i-1]+a;
       b--;  
    } 
    return dp[n];
    }
};