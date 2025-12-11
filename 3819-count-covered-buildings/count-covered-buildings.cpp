class Solution {
public:
    int countCoveredBuildings(int n,vector<vector<int>>& b1) {
    unordered_map<int,vector<int>>rows,cols;
    for(auto it:b1)
    {
        int x=it[0];
        int y=it[1];
        rows[x].push_back(y);
        cols[y].push_back(x);
    }
    for(auto &[a,b]:rows)
    {
        sort(b.begin(),b.end());
    }
    for(auto &[a,b]:cols)
    {
        sort(b.begin(),b.end());
    }
    int result=0;
    for(auto &it:b1)
    {
        int x=it[0];
        int y=it[1];

        auto &ry=rows[x];

        auto ity=lower_bound(ry.begin(),ry.end(),y);
        bool le=(ity!=ry.begin());

        auto ity1=upper_bound(ry.begin(),ry.end(),y);
        bool ri=(ity1!=ry.end());

        auto &cx =cols[y];

        auto itx=lower_bound(cx.begin(),cx.end(),x);
        bool up=(itx!=cx.begin());

        auto itx1=upper_bound(cx.begin(),cx.end(),x);
        bool dow=(itx1!=cx.end());
        if(le && ri && up && dow)
        {
            result++;
        }
    }
    return  result;
    }
};