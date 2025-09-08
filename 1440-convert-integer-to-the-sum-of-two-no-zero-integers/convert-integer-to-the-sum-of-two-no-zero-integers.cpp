class Solution {
public:
    bool f(int x)
    {
        while(x>0)
        {
            if(x%10==0)
            return false;
            x=x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
    for(int i=1;i<n;i++)
    {
        int j=n-i;
        if(f(i) && f(j))
        {
            return {i,j};
        }
    }   
    return {};
    }
};