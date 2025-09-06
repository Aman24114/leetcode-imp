// 4 ^ (k-1) to 4^k -1 need k operations 
// result / 2 becuase of pairs 
// result% 2 for remaining
#define ll long long 
class Solution {
public:
    ll f(ll limit)
    {   
        int cur=0;
        int i=1;
        ll ans=0;
        while(cur<limit)
        {
            ll next=((cur+1)*4)-1;
            next=min(next,limit);
            ans+=(next-cur)*1LL*i;
            i++; // no of operations 
            cur=next;
        }
        return ans;
    }
    ll minOperations(vector<vector<int>>& q) {
    ll ans=0;
    for(auto it:q)
    {
        ll res= f(it[1])-f(it[0]-1);
        ans+= res/2+res%2; 
    }
    return ans;
    }
};