class Solution {
public:
    void computelps(string &pat,vector<int>&lps,int m)
    {
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<m)
        { 
           if(pat[i]==pat[len])
           {
               len++;
               lps[i]=len;
               i++;
           }
           else if(len!=0)
           {
               len=lps[len-1];
           }
           else
           {
               lps[i]=0;
               i++;
           }
        }
    }
    vector<int> kmp(string& pat, string& txt) {
    int n=txt.length();
    int m=pat.length();
    vector<int>result;
    vector<int>lps(m,0);
    computelps(pat,lps,m);
    int i=0;
    int j=0;
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            result.push_back(i-m);
            j=lps[j-1];
        }
        else if(i<n && txt[i]!=pat[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else 
            {
                i++;
            }
        }
    }
    return result;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
    int n=s.length();
    vector<int> i1=kmp(a,s);
    vector<int> j1=kmp(b,s);
    vector<int>result;
    for(auto it:i1)
    {
        int ll=max(0,it-k);
        int rl=min(n-1,it+k);
        auto it1 = lower_bound(begin(j1),end(j1),ll);
        if(it1!=j1.end() && *it1<=rl)
        {
            result.push_back(it);
        }
    }
    return result;
    }
};