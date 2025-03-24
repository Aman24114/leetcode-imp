class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
    int n=m.size();
    sort(m.begin(),m.end());
    int s=0,e=0,ans=0;
    for(auto &it:m)
    {
    if(it[0]>e)
    {
        ans+=it[0]-e-1; 
    }
    e=max(e,it[1]); // ovrlapping intervlas ke liye 
    }
    if(days>e)
    {
      ans+=days-e;
    }
    return ans;
    }
};