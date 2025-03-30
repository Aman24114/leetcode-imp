class Solution {
public:
    vector<int> partitionLabels(string s) {
    unordered_map<int,pair<int,int>>mp;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(mp.find(s[i])==mp.end())
        {
            mp[s[i]]={i,i};
        }
        mp[s[i]].second=i;
    } 
    vector<pair<int,int>>v;
    for(auto &it:mp)
    {
        v.push_back(it.second);
    }   
    sort(v.begin(),v.end());
    vector<int>res;
    int a=v[0].first,b=v[0].second;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first<=b)
        {
            b=max(b,v[i].second);
        }
        else
        {
            res.push_back(b-a+1);
            a=v[i].first,b=v[i].second;
        }
    }
    res.push_back(b-a+1);
    return res;
    }
};