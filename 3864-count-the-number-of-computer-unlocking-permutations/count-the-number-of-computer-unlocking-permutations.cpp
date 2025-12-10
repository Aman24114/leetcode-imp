#define ll long long 
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
    ll mod=1e9+7;
    ll ans=1;
    int root=complexity[0];
    int n=complexity.size();

    for(int i=1;i<n;i++){
    if(complexity[i]<=root)
    return 0;
    }
    
    for(int i=1;i<=n-1;i++){
    ans*=i;
    ans=ans%mod;
    }
    return (int)ans;
    }
};