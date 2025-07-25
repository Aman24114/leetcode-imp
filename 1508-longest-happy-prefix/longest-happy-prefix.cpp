class Solution {
public:
    vector<int>computelps(string w)
    {
        vector<int>lps(w.length(),0);
        int idx=0;
        for(int i=1;i<w.length();)
        {
            if(w[i]==w[idx])
            {
                idx++;
                lps[i]=idx;
                i++;
            }
            else
            {
                if(idx!=0)
                {
                    idx=lps[idx-1];// get back to the part where matching has been done till now
                }
                else 
                i++;
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
    vector<int>lps=computelps(s);
    return s.substr(0,lps.back());
    }
};