// bs diffrence pe lagao 
// check karlo p pairs ban paa raha hai ki nahin 
class Solution {
public:
    bool f(vector<int>&nums,int mid,int p)
    {
        int i=0,cnt=0,n=nums.size();
        while(i<n-1)
        {
            if((nums[i+1]-nums[i])<=mid)
            {
            cnt++;  
            i+=2; 
            }
            else
            {
            i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
    int n=nums.size();
    int ans=0;
    sort(nums.begin(),nums.end());
    int l=0;
    int r=nums[n-1]-nums[0];
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(f(nums,mid,p))
        {
           ans=mid;
           r=mid-1;   
        }
        else
        {
           l=mid+1;
        }
    }
    return ans;
    }
};