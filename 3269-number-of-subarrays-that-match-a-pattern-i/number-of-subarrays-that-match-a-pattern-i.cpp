class Solution {
public:
    void clps(vector<int>&pattern,vector<int>&lps)
    {
        int m=pattern.size();
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<m)
        {
            if(pattern[i]==pattern[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else 
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    int n=nums.size();
    int m=pattern.size();
    vector<int>txt;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]<nums[i+1])
        {
            txt.push_back(1);
        }
        if(nums[i]>nums[i+1])
        {
            txt.push_back(-1);
        }
        if(nums[i]==nums[i+1])
        {
            txt.push_back(0);
        }
    }
        vector<int>lps(m,0);
        clps(pattern,lps);
        int i=0;
        int j=0;
        int count=0;
        while(i<txt.size())
        {
            if(pattern[j]==txt[i])
            {
                i++;
                j++;
            }
            if(j==pattern.size())
            {
                count++;
                j=lps[j-1];
            }
            else if(i<txt.size() && pattern[j]!=txt[i])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else 
                {
                    i++;
                }
            }
        }
    return count;
    }
};