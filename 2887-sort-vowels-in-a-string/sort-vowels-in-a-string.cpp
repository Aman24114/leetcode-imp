class Solution {
public:
    static bool cmp(char &a,char &b)
    {
        return a<b;
    }
    string sortVowels(string s)
    {
         string p="";
         set<char> d={'A','E','I','O','U','a','e','i','o','u'};
         for(int j=0;j<s.size();j++)
         {
            if(d.find(s[j])!=d.end())
            {
                p+=s[j];
            }
         }
         sort(p.begin(),p.end(),cmp);
         int i=0;
         for(int j=0;j<s.size();j++)
         {
            if(d.find(s[j])!=d.end())
            {
                s[j]=p[i++];
            }
         }
         return s;
    }
};