class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<int> v(n*n+1,0);
    int r1,s=-1;
    for(const auto& r:grid)
    {
        for(int num:r)
        {
            v[num]++;
        }
    } 
    for(int i=0;i<n*n+1;i++)
    {
        if(v[i]==2)
        r1=i;
        if(v[i]==0)
        s=i;
    }
    return {r1,s};
    }
};