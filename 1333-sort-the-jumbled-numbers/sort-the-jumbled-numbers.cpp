class Solution {
public:
    typedef pair<int,int> p;
    string f(string &s,vector<int>mapping)
    {
        string result="";
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            int j=ch-'0';
            result+=to_string(mapping[j]);
        }
        return result;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    int n=nums.size();
    vector<p>v;
    for(int i=0;i<n;i++)
    {
      string numstr=to_string(nums[i]);
      string mpstr=f(numstr,mapping);
      int mpnum=stoi(mpstr);
      v.push_back({mpnum,i});
    }
    sort(v.begin(),v.end());
    vector<int>result;
    for(auto &it:v)
    {
        int ind=it.second;
        result.push_back(nums[ind]);
    } 
    return result;
    }
};