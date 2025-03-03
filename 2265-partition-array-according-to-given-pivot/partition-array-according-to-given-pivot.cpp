class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
    vector<int>v(nums.size());
    int l=0;int r=nums.size()-1;int cnt=0;
    for(int n:nums)
    {
        if(n<p)
        {
            v[l++]=n;
        }
        else if(n==p)
        {
            cnt++;
        }
    }
    int mid=l;
    while(cnt--)
    {
        v[l++]=p;
    }   
    for(int n:nums)
    {
        if(n>p)
        {
            v[l++]=n;
        }
    }
    return v;
    }
};