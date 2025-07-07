class Solution {
public:
    vector<string>v;
    unordered_map<char,string>mp;
    unordered_map<string,int>vis;
    bool wordPattern(string pattern, string s) {
    string val="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ')
        {
            val+=s[i];
        }
        else if(s[i]==' ')
        {
            v.push_back(val);
            val="";
        }
    }
    v.push_back(val);
    if(pattern.size()!=v.size())
    {
        return 0;
    }
    for(int i=0;i<pattern.size();i++)
    {
        if(mp.find(pattern[i])==mp.end())
        {
            if(vis.size()>0)
            {
                if(vis.find(v[i])!=vis.end())
                {
                    return 0;
                }
                else if(vis.find(v[i])==vis.end())
                {
                    vis[v[i]]++;
                }
            }
            mp[pattern[i]]=v[i];
            vis[v[i]]++;
            }
            else if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=v[i])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};