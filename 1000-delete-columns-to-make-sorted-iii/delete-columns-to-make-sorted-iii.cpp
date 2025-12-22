// dp[j]= no of columms can be kept uptil j
class Solution {
public:
    int minDeletionSize(vector<string>& s){
    int n=s.size();
    int m=s[0].size();
    vector<int>dp(m,1);
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<j;i++)
        {
            bool ok=true;
            for(int r=0;r<n;r++)
            {
                if(s[r][i]>s[r][j])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            dp[j]=max(dp[j],dp[i]+1);
        }
    }
    int maxi=*max_element(dp.begin(),dp.end());
    return m-maxi;
    }
};