class Solution {
public:
    static bool lambda(int a,int b)
    {
       int setbita=__builtin_popcount(a);
       int setbitb=__builtin_popcount(b);
       if(setbita== setbitb)
       {
         return a<b;
       }   
       return  setbita<setbitb;
    }
    vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(),arr.end(),lambda);
    return arr;
    }
};