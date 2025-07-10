class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool>ans;
    for(int i=0;i<l.size();i++)
    {
        int s=l[i];
        int e=r[i];
        bool b=true;
        vector<int>v;
        for(int j=s;j<=e;j++)
        {
            v.push_back(nums[j]);
        }
        sort(v.begin(),v.end());
        int diff=v[1]-v[0];
        for(int j=1;j<v.size();j++)
        {
           if(!b)
           {
             break;
           }
           b=b && (diff==abs(v[j]-v[j-1]));
        }
        ans.push_back(b);
    }
    return ans;    
    }
};