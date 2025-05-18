class Solution {
public:
    vector<string>c;
    vector<vector<int>>dp;
    int M=1e9+7;
    void f1(string curr,char prev,int l,int m)
    {
       if(l==m)
       {
         c.push_back(curr);
         return;
       }
       for(char ch :{'R','G','B'})
       {
          if(ch==prev)
          continue;
          f1(curr+ch,ch,l+1,m);
       }
    }
    int f(int remcol,int previdx,int m)
    {
        if(remcol==0)
        {
            return 1;
        }
        if(dp[remcol][previdx]!=-1)
        return dp[remcol][previdx];
        int ways=0;
        string prevs=c[previdx];
        for(int i=0;i<c.size();i++)
        {
            if(i==previdx)
            continue;
            string currs=c[i];
            bool valid=true;
            for(int j=0;j<m;j++)
            {
                if(prevs[j]==currs[j])
                {
                    valid=false;
                    break;
                }
            }
            if(valid)
            {
                ways=(ways+f(remcol-1,i,m))%M;
            }
        }
        return dp[remcol][previdx]=ways;
    }
    int colorTheGrid(int m, int n)
    {

     f1("",'p',0,m);
     int ans=0;
     dp=vector<vector<int>>(n+1,vector<int>(c.size()+1,-1));
     for(int i=0;i<c.size();i++)
     {
        ans=(ans+f(n-1,i,m))%M; 
     } 
     return ans;   
    }
};