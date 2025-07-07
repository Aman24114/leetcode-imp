class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>,int>v;
    int row=grid.size();
    int col=grid[0].size();
    int ans=0;
    for(vector<int>row:grid)
    {
       v[row]+=1;
    }    
    for(int i=0;i<row;i++)
    {
        vector<int>col1={};
        for(int j=0;j<col;j++)
        {
            col1.push_back(grid[j][i]);
        }
        ans+=v[col1];
    }
    return ans;
    }
};