#define d double 
class Solution {
public:
    d maxi=-1.0,ans=-1.0;
    int res=0;
    int areaOfMaxDiagonal(vector<vector<int>>& dim){
    for(int i=0;i<dim.size();i++)
    {
       int l=dim[i][0],b=dim[i][1];
       ans=sqrt(l*l*1.0 + b*b*1.0);
       if(ans>maxi)
       {
          maxi=ans;
          res=l*b;
       }
       else if(ans == maxi)
       {
         res=max(res,l*b);
       }
    }  
    return res;
    }
};