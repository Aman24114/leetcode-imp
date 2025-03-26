class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
    vector<int>v;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            v.push_back(grid[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int m=v[v.size()/2];
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        if((v[i]-m)%x!=0)
        return -1;
        cnt+=(abs(v[i]-m)/x);
    }
    return cnt;
    }
};