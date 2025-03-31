#define ll long long 
class Solution {
public:
    ll putMarbles(vector<int>& w, int k)
    {
       ll ans=0;
       vector<int>v(w.size()-1,0);
       for(int i=0;i<w.size()-1;i++)
       {
        v[i]=w[i]+w[i+1];
       }
       int n=v.size();
       sort(v.begin(),v.end());
       for(int i=0;i<k-1;i++)
       {
        ans+=v[n-i-1]-v[i];
       }
       return ans;
    }
};