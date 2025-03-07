class Solution {
public:
    int f(int n,int p)
    {    
        if(n==0)
        return true;
        if(pow(3,p)>n)
        return false; 
        int a= f(n-pow(3,p),p+1);
        int  b= f(n,p+1);
        return a||b;
    }
    bool checkPowersOfThree(int n) {
    return f(n,0);     
    }
};