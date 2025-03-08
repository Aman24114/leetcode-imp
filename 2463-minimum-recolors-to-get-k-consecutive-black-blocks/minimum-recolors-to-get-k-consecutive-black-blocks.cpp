class Solution {
public:
    int minimumRecolors(string b, int k) {
    int n=b.size();
    vector<int>v(n+1,0);
    for(int i=0;i<n;i++)
    {
       v[i+1]=v[i]+(b[i]=='W'?1:0);
    }
    int mini=n;
    for(int i=k;i<=n;i++)
    {
     mini=min(mini,v[i]-v[i-k]);   
    }
    return mini;
    }
};