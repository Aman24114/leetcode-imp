class Solution {
public:
    void f1(vector<string>e,vector<int>&mc,vector<int>&ft)
    {
        int timestamp=stoi(e[1]);
        vector<string>ids;
        stringstream ss(e[2]);
        string token;
        while(ss>>token)
        {
            ids.push_back(token);
        }
        for(string id:ids)
        {
            if(id=="ALL")
            {
                for(int i=0;i<mc.size();i++)
                {
                    mc[i]++;
                }
            }
            else if(id=="HERE")
            {
                for(int i=0;i<mc.size();i++)
                {
                    if(ft[i]==0 || ft[i]+60<=timestamp)
                    {
                        mc[i]++;
                    }
                }
            }
            else 
            {
                mc[stoi(id.substr(2))]++;
            }
        }
    }
    vector<int> countMentions(int n,vector<vector<string>>&e)
    {
       vector<int>mc(n);
       vector<int>ft(n);
       auto lambda=[](vector<string>&vec1,vector<string>&vec2)
       {
          int t1=stoi(vec1[1]);
          int t2=stoi(vec2[1]);
          if(t1==t2)
          return vec1[0][1]>vec2[0][1];
          return t1<t2;
       };
       sort(e.begin(),e.end(),lambda);
       for(vector<string>e1:e)
       {
          if(e1[0]=="MESSAGE")
          {
            f1(e1,mc,ft);
          }
          else if(e1[0]=="OFFLINE")
          {
             int timestamp=stoi(e1[1]);
             int id=stoi(e1[2]);
             ft[id]=timestamp;
          }
       }
       return mc;
    }
};