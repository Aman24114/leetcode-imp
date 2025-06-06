class Solution {
public:
    string robotWithString(string s)
    {
        int n=s.length();
        vector<char>postmin(n);
        postmin[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            postmin[i]=min(s[i],postmin[i+1]);
        } 
        string t="",p="";
        int i=0;
        for(int i=0;i<n;i++)
        {
            t.push_back(s[i]);
            char c=(i+1<n)? postmin[i+1]:s[i];
            while(!t.empty() && t.back()<=c)
            {
                p+=t.back();
                t.pop_back();
            }
        }
        while(!t.empty())
        {
            p+=t.back();
            t.pop_back();
        }
        return p;
    }
};