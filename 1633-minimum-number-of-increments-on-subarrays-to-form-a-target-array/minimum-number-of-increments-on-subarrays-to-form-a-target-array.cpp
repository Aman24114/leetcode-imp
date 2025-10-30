class Solution {
public:
    int minNumberOperations(vector<int>& t) {
    int n=t.size();
    int ans=t[0];
    for(int i=1;i<n;i++)
    {
        if(t[i]>t[i-1])
        ans+=(t[i]-t[i-1]);
    }
    return ans;
    }
};