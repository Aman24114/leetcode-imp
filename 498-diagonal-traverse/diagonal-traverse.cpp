class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int>arr;
    int i=0;
    int j=0; 
    int n=mat.size();
    int m=mat[0].size();
    while(arr.size()<n*m)
    {
       arr.push_back(mat[i][j]);
       if((i+j)%2==0)
       {
         if(j==mat[0].size()-1)
         {
            i++;
         }
         else if(i==0)
         {
            j++;
         }
         else 
         {
            i--;
            j++;
         }
       }
       else 
       {
         if(i==mat.size()-1)
         {
            j++;
         }
         else if(j==0)
         {
            i++;
         }
         else 
         {
            i++;
            j--;
         }
       }
    } 
    return arr;  
    }
};