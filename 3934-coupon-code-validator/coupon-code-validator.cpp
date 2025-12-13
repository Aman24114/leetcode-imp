class Solution {
public:
    bool vc(string &s)
    {
        if(s.empty())
        return false;
        for(auto it:s)
        {
            if(it=='_')
            continue;
           if (!isalnum(it))
            return false;
        }
        return true;
    }
    bool vb(string &s1)
    {
        if(s1=="electronics" || s1=="grocery" || s1=="pharmacy"|| s1=="restaurant")
        return true;
        return false;
    }
    static int order(const string&cat)
    {
        if(cat=="electronics")
        return 0;
        if(cat=="grocery")
        return 1;
        if(cat=="pharmacy")
        return 2;
        return 3;
    }
    static bool lambda(pair<string,string>&a,pair<string,string>&b)
    {
       int pa=order(a.first);
       int pb=order(b.first);
       if(pa!=pb)
       return pa<pb;
       return a.second<b.second;
    }
    vector<string> validateCoupons(vector<string>& c, vector<string>& b, vector<bool>& ac) {
    vector<pair<string,string>>p;
    for(int i=0;i<c.size();i++)
    {
        if(vc(c[i])&& vb(b[i])&& ac[i])
        {
          p.push_back({b[i],c[i]});  
        }
    }
    sort(p.begin(),p.end(),lambda);
    vector<string>ans;
    for(auto it:p)
    {
        ans.push_back(it.second);
    }
    return ans;
    }
};