class Solution {
public:
    void sortColors(vector<int>& nums) {
     int k=0,l=0,m=0;
     for(int i=0;i<nums.size();i++)
      {
        if (nums[i]==0)  
        {
            k++;
        }
        if (nums[i]==1)  
        { 
            l++;
        }
        if (nums[i]==2)  
        { 
            m++;
        }
      }
      nums.clear();
      for (int i=0;i<k;i++)
      {
        nums.push_back(0);    
      }
      for (int i=0;i<l;i++)
      {
        nums.push_back(1);    
      }
      for (int i=0;i<m;i++)
      {
        nums.push_back(2);    
      }
    }
};