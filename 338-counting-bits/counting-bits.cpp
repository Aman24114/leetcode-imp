class Solution {
public:
    vector<int> countBits(int n) {
     // count the number of set bits 
     vector<int> ans;
     for(int i=0;i<=n;i++)
     {
         int sum=0;
         int num=i;
         while(num!=0)
         {
             // we have to xounth the number of ones
             sum+=num%2;
             num=num/2;
         }
         ans.push_back(sum);
     } 
     return ans;  
    }
};