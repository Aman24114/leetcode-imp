class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
    int n = ma.size();
    int m = ma[0].size();
    set<int> r,c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ma[i][j]==0)
            {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((r.count(i)>0)||(c.count(j)>0))
            {
                ma[i][j]=0;
            }
        }
    }
    }
};