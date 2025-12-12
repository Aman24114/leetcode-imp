class Solution {
public:
    int f(vector<vector<bool>>&dp,int i,int j,string &s)
    {
        if(i==j)
        return dp[i][j]=true;
        if(j-i==1)
        {
            if(s[i]==s[j])
            return dp[i][j]=true; 
            else 
            return dp[i][j]=false;
        }
        if(s[i]==s[j]&&dp[i+1][j-1]==true)
        return dp[i][j]=true;
        else 
        return dp[i][j]=false;
    }
    string longestPalindrome(string s) {
    int n=s.size();
    int idx=0,maxlen=0;
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {
            f(dp,i,j,s);
            if(dp[i][j]==true)
            {
                if(j-i+1>maxlen)
                maxlen=j-i+1;
                idx=i;
            }
        }
    }
    return s.substr(idx,maxlen);    
    }
};