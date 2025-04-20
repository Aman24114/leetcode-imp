class Solution {
public:
    int numRabbits(vector<int>& ans)
    {
        unordered_map<int,int>mp;
        for(auto it:ans)
        {
            mp[it]++;
        }
        int res=0;
        for(auto it:mp)
        {
            int grp=ceil((it.second*1.0)/(it.first+1));
            res+=grp*(it.first+1);
        }
        return res;
    }
};