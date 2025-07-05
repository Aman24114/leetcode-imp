class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
       int x=(a|b)^c;
       int y= (a&b&x);
       return __builtin_popcount(x)+ __builtin_popcount(y);
    }
};