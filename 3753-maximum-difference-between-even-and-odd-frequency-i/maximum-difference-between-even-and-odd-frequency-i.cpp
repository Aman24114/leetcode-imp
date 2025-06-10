class Solution {
public:
    int maxDifference(string s)
    {
        vector<int>v(26, 0);
        for (char it:s)
        {
            v[it-'a']++;
        }
        int o= INT_MIN, e = INT_MAX;
        for (int f : v)
        {
            if (f>0)
            {
                if (f%2==1)
                {
                    o=max(o,f);
                }
                else
                {
                   e=min(e,f);
                }
            }
        }
        return o-e;
    }
};