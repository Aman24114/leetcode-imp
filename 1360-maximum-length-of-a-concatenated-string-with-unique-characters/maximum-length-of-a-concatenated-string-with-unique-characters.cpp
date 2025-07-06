class Solution {
public:
    void f(int idx,int temp,int &result,vector<int>&v)
    {
        result=max(result,__builtin_popcount(temp));
        for(int i=idx;i<v.size();i++)
        {
            if((temp & v[i])==0)
            {
                f(i+1,temp|v[i],result,v);
            }
        }
    }
    int maxLength(vector<string>& arr)
    {
      vector<int>v;
      for(string &s:arr)
      {
        unordered_set<char>st(s.begin(),s.end());
        if(st.size()!=s.length())
        {
            continue;
        }
        int val=0;
        for(char &ch:s)
        {
            val=(val|(1<<(ch-'a')));
        }
        v.push_back(val);
      }
      int result=0;
      int temp=0;
      f(0,temp,result,v);
      return result;
    }
};