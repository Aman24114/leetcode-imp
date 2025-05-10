#define ll long long
class Solution {
public:
    ll minSum(vector<int>& n1 , vector<int>& n2)
    {
        ll n1s=0,n2s=0;
        ll n1z=0,n2z=0;
        for(auto &it:n1)
        {
            if(it==0)
            {
                n1z++;
                n1s++;
            }
            else
            {
                n1s+=it;
            }
        }
        for(auto &it:n2)
        {
            if(it==0)
            {
                n2z++;
                n2s++;
            }
            else
            {
                n2s+=it;
            }
        }
        if((n1z==0 && n2s>n1s)||(n2z==0 && n1s>n2s))
        return -1;
        return max(n1s,n2s);
    }
};