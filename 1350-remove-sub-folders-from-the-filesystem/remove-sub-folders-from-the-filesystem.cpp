class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f)
    {
        unordered_set<string>st(begin(f),end(f));
        vector<string>r;
        for(auto &it:f)
        {   
            string s=it;
            bool b=false;
            while(!it.empty())
            {
                size_t pos= it.find_last_of('/');
                it=it.substr(0,pos);
                if(st.find(it)!=st.end())
                {
                   b=true;
                   break;
                }
           }
           if(!b)
           {
               r.push_back(s);
           }
        } 
        return r; 
    }
};