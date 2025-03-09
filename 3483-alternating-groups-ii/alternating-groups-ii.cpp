class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
    int maxi=1,ans=0,n=c.size();  
    for(int i=1;i<=n+k-2;i++)
    {
        if(c[i%n]!=c[(i-1+n)%n])
        {
            maxi++;
        }
        else
        {
            maxi=1;
        }
        if(maxi>=k)
        {
            ans++;
        }
    }
    return ans;  
    }
};