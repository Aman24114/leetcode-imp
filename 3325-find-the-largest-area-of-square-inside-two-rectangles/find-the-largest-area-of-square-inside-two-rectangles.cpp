#define  ll long long 
class Solution {
public:
    ll largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
    ll maxi=0;
    int n=bl.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll x1=max(bl[i][0],bl[j][0]);
            ll y1=max(bl[i][1],bl[j][1]);
            ll x2=min(tr[i][0],tr[j][0]);
            ll y2=min(tr[i][1],tr[j][1]);
            
            ll w=x2-x1 ,h=y2-y1;
            if(w>0 && h>0)
            {
                ll curr=min(w,h);
                maxi=max(curr,maxi);
            }
        }
    } 
    return maxi*maxi;
    }
};