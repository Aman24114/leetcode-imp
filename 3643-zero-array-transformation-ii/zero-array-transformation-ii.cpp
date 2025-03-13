class Solution {
public:
    bool f2(vector<int>&nums,vector<vector<int>>&queries,int k)
    {   int sum=0;
        int n=nums.size();
        vector<int>dif(n+1,0);
        for(int i=0;i<=k;i++)
        {
            int l=queries[i][0],r=queries[i][1],x=queries[i][2];
            dif[l]+=x;
            if(r+1<nums.size())
            dif[r+1]-=x;
        }
        for(int i=0;i<nums.size();i++)
        {
            sum+=dif[i];
            dif[i]=sum;
            if(nums[i]-dif[i]>0)
            {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n=nums.size();
    int k=-1;
    auto fun=[](int x)
    {
        return x==0;
    };
    if(all_of(begin(nums),end(nums),fun))
    return 0;
    int l=0;
    int r=queries.size()-1;
    while(l<=r)
    {
        int mid=l+(r-l/2);
        if(f2(nums,queries,mid)==true)
        {
            k=mid+1;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return k;    
    }
};