class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& dig)
    {
        int n=dig.size();
        set<int>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i==j || j==k || i==k)
                    {
                        continue;
                    }
                    int num=dig[i]*100 + dig[j]*10 +dig[k]*1;
                    if(dig[i]!=0 && num%2==0)
                    {
                        st.insert(num);
                    }
                }
            }
        }
        vector<int>ans(st.begin(),st.end());
        return ans;     
    }
};