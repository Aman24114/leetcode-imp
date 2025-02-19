class Solution {
static bool cmp(vector<int>&a,vector<int>&b)
{   
    if(a[0]==b[0])
    {
        return a[1]>b[1];
    }
    return a[0]<b[0];
}
public:
    int maxEnvelopes(vector<vector<int>>& e) {
    int n=e.size();
    sort(e.begin(),e.end(),cmp);
    vector<int>ans;
    ans.push_back(e[0][1]);
    for(int i=1;i<n;i++)
    {
    if(e[i][1]>ans.back())
    ans.push_back(e[i][1]);
    else
    {
        int ind=lower_bound(ans.begin(),ans.end(),e[i][1])-ans.begin();
        ans[ind]=e[i][1];
    }    
    }   
    return ans.size();
    }
};