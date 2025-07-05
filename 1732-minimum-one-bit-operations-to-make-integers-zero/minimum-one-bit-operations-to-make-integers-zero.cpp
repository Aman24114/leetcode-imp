#define ll long long 
class Solution {
public:
    int minimumOneBitOperations(int n)
    {
        if(n==0)
        {
            return 0;
        }  
        vector<ll>f(31,0);
        f[0]=1;
        for(int i=1;i<=30;i++)
        {
           f[i]=2*f[i-1]+1;
        }
        int result=0;
        int sign=1;
        for(int i=30;i>=0;i--)
        {
            int ibit= ((1<<i)&n);
            if(ibit==0)
            {
                continue;
            }
            if(sign >0)
            {
                result+=f[i];
            }
            if(sign <0)
            {
                result-=f[i];
            }
            sign*=-1;
        }
       return result;
    }
};