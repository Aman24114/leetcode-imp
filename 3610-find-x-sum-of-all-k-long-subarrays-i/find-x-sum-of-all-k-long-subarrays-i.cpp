class Solution {
public:
    bool static cmp(const pair<int,int>&a,const pair<int,int>&b)
    {
        if(a.second==b.second)
        return a.first>b.first;
        return a.second>b.second;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n=nums.size();
    vector<int>ans;
    for(int i=0;i<=n-k;i++)
    {
        vector<int>s(nums.begin()+i,nums.begin()+i+k);
        unordered_map<int,int>f;
        for(auto it:s)
        {
            f[it]++;
        }
        vector<pair<int,int>>v1(f.begin(),f.end());
        sort(v1.begin(),v1.end(),cmp);
        unordered_set<int>st;
        for(int j=0;j<v1.size()&& j<x ;j++)
        {
            st.insert(v1[j].first);
        }
        int sum=0;
        for (auto it : s){
        if (st.count(it))
        sum += it;
        }
        ans.push_back(sum);
    }
    return ans;
    }
};