class Solution {
private:
    vector<int> ans;
    void f(int i, int n)
    {
        if(i>n)
        {
            return;
        }
        int cur = i; 
        ans.push_back(cur);
        for(int i=0;i<=9;i++)
        {
            int tmp = cur*10+i;
            f(tmp,n);
        }
    }
    public:
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++)
        {
            f(i,n);
        }
        return ans;
    }
};