#define ll long long
class Solution {
public:
    int mod=1e9+7;
    ll tperm=0;
    int n;
    int nsum;
    int be(ll a,ll b)
    {
       if(b==0)
       {
         return 1;
       }
       ll half=be(a,b/2);
       ll ans=(half*half)%mod;
       if(b%2==1)
       {
        ans=(ans*a)%mod;
       }
       return ans;
    }
    int f1(int digit, int evendigcnt,int currsum,vector<ll>&freq,vector<ll>&invfact,vector<vector<vector<int>>>&dp)
    {
        if(digit==10)
        {
            if(currsum == nsum/2 && evendigcnt == (n+1)/2)
            return tperm;
            return 0;
        }
        if(dp[digit][evendigcnt][currsum]!=-1)
        {
            return dp[digit][evendigcnt][currsum];
        }
        ll ways=0;
        for(int cnt=0;cnt<=min<ll>(freq[digit], (n+1)/2-evendigcnt);cnt++)
        {
            int evenposcnt=cnt;
            int oddposcnt= freq[digit]-cnt;
            ll div=(invfact[evenposcnt]*invfact[oddposcnt])%mod;
            ll val=f1(digit+1,evendigcnt+evenposcnt,currsum + digit*cnt,freq,invfact,dp);
            ways = (ways+(val*div))%mod;
        }
        return dp[digit][evendigcnt][currsum]= ways;
    }
    int countBalancedPermutations(string num) {
    int n1=num.size();
    this-> n=n1;
    int nsum1=0;
    vector<ll>freq(10,0);

    for(int i=0;i<n;i++)
    {
        nsum1+=num[i]-'0';
        freq[num[i]-'0']++;
    }  
    nsum=nsum1;
    if(nsum1%2!=0)
    {
        return 0;
    }

    vector<ll>fact(n+1,1);
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=n;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    vector<ll>invfact(n+1,1);
    {
        for(int i=0;i<=n;i++)
        {
            invfact[i]=be(fact[i],mod-2)%mod;
        }
    } 
    
    tperm = (1LL*fact[(n+1)/2]*fact[n/2])%mod;

    int digit=0;
    int evendigcnt=0;
    int cursum=0;
    vector<vector<vector<int>>> dp(10,vector<vector<int>>((n+1)/2+1,vector<int>(nsum+1,-1)));
    return f1(0,0,0,freq,invfact,dp);
    }
};