// boore moyre algo 
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
    int n=nums.size();
    int maxi=-1,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            maxi=nums[i];
            cnt=1;
        }
        else if(maxi==nums[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int maxicnt=0;
    for(auto &it:nums)
    {
        if(it==maxi)
        {
        maxicnt++;
        }
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==maxi)
        {
          cnt1++;   
        }
        int n1=i+1;
        int n2=n-i-1;
        cnt2=maxicnt-cnt1;
        if(cnt1>n1/2 && cnt2>n2/2)
        {
            return i;
        }
    }
    return -1;
    }
};