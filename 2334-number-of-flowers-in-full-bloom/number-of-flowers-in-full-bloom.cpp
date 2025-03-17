class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
    int m=f.size();
    int n=p.size();
    vector<int>s(m,0);
    vector<int>e(m,0);
    vector<int>ans(n,0);
    for(int i=0;i<m;i++)
    {
        s[i]=f[i][0];
        e[i]=f[i][1];
    }
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    for(int i=0;i<n;i++)
    {
        int t=p[i];
        int bloom= upper_bound(begin(s),end(s),t)-begin(s);
        int die= lower_bound(begin(e),end(e),t)-begin(e);
        ans[i]=(bloom-die);
    }
    return ans;
    }
};