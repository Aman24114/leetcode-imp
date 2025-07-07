class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<vector<int>>ans;
    unordered_map<int,int>lost;
    for(auto &it:matches)
    {
        if(!lost.count(it[0]))
        {
            lost[it[0]]=0;
        }
       lost[it[1]]++;
    } 
    vector<int>win;
    vector<int>lose;
    for(auto it:lost)
    {
        if(it.second==0)
        {
            win.push_back(it.first);
        }
        else if(it.second==1)
        {
            lose.push_back(it.first);
        }
    } 
    sort(win.begin(), win.end());
    sort(lose.begin(), lose.end());
    ans.push_back(win);
    ans.push_back(lose);
    return ans;
    }
};
