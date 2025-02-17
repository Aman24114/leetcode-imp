class Solution {
public:
     unordered_map<int,int>par;
     unordered_map<int,int>size;
     void f(int u)
     {
        par[u]=u;
        size[u]=1;
     }
     int find(int u)
     {
        if(par[u]==u)
        return u;
        return par[u]=find(par[u]);
     }
     void Union(int x,int y)
     {
        int a= find(x);
        int b= find(y);
        if(a!=b)
        {
            if(size[b]>size[a])
            {
                swap(b,a);
            }
            par[b]=a;
            size[a]+=size[b];
        }
     }
    int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
       f(nums[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(par.find(nums[i]+1)!=par.end())
        {
            Union(nums[i],nums[i]+1);
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,size[nums[i]]);
    }
    return maxi;
    }
};