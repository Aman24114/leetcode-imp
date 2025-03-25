class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>result;
    result.push_back(intervals[0]);
    for(int i=1;i<n;i++)
    {
        if(intervals[i][0]<result.back()[1])
        {
            result.back()[1]=max(result.back()[1],intervals[i][1]);
        }
        else
        {
            result.push_back(intervals[i]);
        }
    }  
    return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
    vector<vector<int>>h,v;
    if(rect.empty())
    return false;
    for(auto &it:rect)
    {
        int x1=it[0];
        int y1=it[1];
        int x2=it[2];
        int y2=it[3];
        h.push_back({x1,x2});
        v.push_back({y1,y2});
    }
    vector<vector<int>>ans1=merge(h);
    if(ans1.size()>=3)
    return true;
    vector<vector<int>>ans2=merge(v);
    if(ans2.size()>=3)
    return true;
    return false;
    }
};