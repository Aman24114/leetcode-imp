#define ll long long 
class Solution {
public:
     const int mod =1e9+7;
     ll findpower(ll a, ll b)
     {
        if(b==0)
        return 1;
        ll half=findpower(a,b/2);
        ll result=(half*half)%mod;
        if(b%2==1)
        result=(result*a)%mod;
        return result;
     }
     vector<int>getprimes(int limit)
     {
        vector<int>isprime(limit+1,true);
        vector<int>primes;
        for(int i=2;i*i<=limit;i++)
        {
            if(isprime[i])
            {
                for(int j=i*i;j<=limit;j+=i)
                {
                    isprime[j]=false;
                }
            }
        }
        for(int i=2;i<=limit;i++)
        {
          if(isprime[i])
          primes.push_back(i);
        }
        return primes;
     }
    
    vector<int>findps(vector<int>&nums)
    {
       int n=nums.size();
       vector<int>primescores(n,0);
       int maxi= *max_element(nums.begin(),nums.end());
       vector<int>primes=getprimes(maxi);// maxi element tak ka primes ismein milega  
       for(int i=0;i<n;i++)
       {
        int num=nums[i];
        for(int prime:primes)
        {
            if(prime*prime>num)
            {
             break;
            }
            if(num%prime!=0)
            {
                continue;
            }
            primescores[i]++;
            while(num%prime ==0)
            {
                num/=prime;
            }
        }
        if(num >1)
        {
         primescores[i]++; 
        }
       }
       return primescores;
    }
    vector<int>findng(vector<int>primescores)
    {
      int n=primescores.size();
      vector<int>nextgreater(n);
      stack<int>st;
      for(int i=n-1;i>=0;i--)
      {
        while(!st.empty()&& primescores[st.top()]<=primescores[i])
        {
         st.pop();   
        }
        nextgreater[i]=st.empty()?n:st.top();
        st.push(i);
      }
      return nextgreater ;
    }
    vector<int>findpg(vector<int>primescores)
    {
      int n=primescores.size();
      vector<int>prevgreater(n);
      stack<int>st;
      for(int i=0;i<n;i++)
      {
        while(!st.empty()&& primescores[st.top()]<primescores[i])
        {
         st.pop();   
        }
        prevgreater[i]=st.empty()?-1:st.top();
        st.push(i);
      }
      return prevgreater ;
    }
    int maximumScore(vector<int>& nums, int k)
    {
        vector<int>primescores = findps(nums);
        vector<int>ng = findng(primescores);
        vector<int>pg = findpg(primescores);
        int n=nums.size();
        vector<ll>subarray(n,0);
        for(int i=0;i<n;i++)
        {
          subarray[i] = (ll)(ng[i]-i)*(i-pg[i]);  
        }
        vector<pair<int,int>>sorted(n);
        for(int i=0;i<n;i++)
        {
            sorted[i]={nums[i],i};
        }
        sort(sorted.rbegin(), sorted.rend());
        ll score=1;
        int idx=0;
        while(k>0)
        {
            auto[num,i]=sorted[idx];
            ll op=min((ll)k,subarray[i]);
            score=(score*findpower(num,op))%mod;
           k=k-op;
           idx++;
        }
       return score;
    }
};