#define ll long long 
class Solution {
public:
    ll countGoodIntegers(int n, int k) 
    {   ll result=0;
        unordered_set<string>st;
        int d=(n+1)/2;
        int s=pow(10, d-1);
        int e=pow(10,d)-1;
        for(int n1=s;n1<=e;n1++)
        {
        
            string lh=to_string(n1);
            string ful="",rh="";
            if(n%2==0)
            {   rh=lh;
                reverse(rh.begin(),rh.end());
                ful=lh+rh;
            }
            else
            {
                rh=lh.substr(0,d-1);
                reverse(rh.begin(),rh.end());
                ful=lh+rh;
            }
            ll n2=stoll(ful);
            if(n2%k!=0)
            {
                continue;
            }
            sort(ful.begin(), ful.end());
            st.insert(ful);
        } 
        vector<ll>factorial(11,1);
        for(int i=1;i<11;i++)
        {
            factorial[i]=factorial[i-1]*i;
        }
        for (const auto &s1 : st) 
        {
            vector<int> dig(10, 0);
            for (char ch : s1)
            {
                dig[ch - '0']++;
            }
            int total= s1.length();
            int zerodig= dig[0];
            int nzdig= total-zerodig;
            ll prem = (nzdig) * factorial[total - 1]; 
            for(int i=0;i<10;i++)
            {
                prem/=factorial[dig[i]];
            }
            result+=prem;
        } 
        return result;
    }
};