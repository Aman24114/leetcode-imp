class Solution {
public:
    vector<int>dp;
    int f(int n)
    {
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            if(f(n-i*i)==0)
            return dp[n]=1;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
    dp.resize(n+1,-1);
    dp[0]=0;
    return f(n);
    }
};