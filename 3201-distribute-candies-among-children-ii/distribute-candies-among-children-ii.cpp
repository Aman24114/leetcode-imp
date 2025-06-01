#define ll long long 
class Solution {
public:
    ll distributeCandies(int n, int limit)
    {  
       ll ans=0;
       for(int i=0;i<=min(n,limit);i++)
       {
          int r=n-i;
          if(r>2*limit)
          continue;
          int j=max(0,r-limit);
          int k=min(r,limit);
          ans+=k-j+1; 
       }
       return ans;
    }
};