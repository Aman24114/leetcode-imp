class Solution {
public:
    vector<int> par, sz;
    int findparent(int u)
    {
        if(par[u] == u)
        return u;
        return par[u]=findparent(par[u]);
    }
    void Union(int u, int v)
    {
        int up = findparent(u);
        int vp = findparent(v);
        if(up == vp)
        return;
        if(sz[up] > sz[vp])
        {
            sz[up]+=sz[vp];
            par[vp]=up;
        }
        else
        {
            sz[vp]+=sz[up];
            par[up]=vp;
        }
    }
    string smallestEquivalentString(string s1, string s2, string b) {
        par.resize(26, 0);
        for(int i=0; i<26; i++)
        {
            par[i] = i;
        }
        sz.resize(26, 0);
        for(int i=0; i<s1.size(); i++)
        {
            int c1 = s1[i]-'a';
            int c2 = s2[i]-'a';
            Union(c1, c2);
        }
        map<int, int> mp;
        for(int i=0; i<par.size(); i++)
        {
            int p = findparent(i);
            if(mp.find(p) == mp.end())
            mp[p] = i;
            else mp[p] = min(mp[p], i);
        }
        string ans;
        for(auto c: b){
            int x = findparent(c-'a');
            ans.push_back(mp[x]+'a');
        }
        return ans;
    }
};