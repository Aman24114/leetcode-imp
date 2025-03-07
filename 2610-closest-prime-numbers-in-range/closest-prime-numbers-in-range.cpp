class Solution {
public:
    vector<int> closestPrimes(int l, int r) {
    vector<bool>prime(r+1,true);
    prime[1]=false;
    prime[0]=false;
    for(int p=2;p*p<=r;p++)
     {
        if(prime[p]==true)
        {
            for(int i=p*p ;i<=r; i+=p)
            {
                prime[i]=false;
            }
        }
     }
        vector<int>temp;
        for(int i=l;i<=r;i++)
        {
            if(prime[i])
            temp.push_back(i);
        }
        vector<int>ans={-1,-1};
        if(temp.size()<2)
        return ans;
        int mini=INT_MAX;
        int t;
        for(int i=1;i<temp.size();i++)
        {
            t=temp[i]-temp[i-1];
            if(mini>t)
            {
            mini=t;
            ans={temp[i-1],temp[i]};
            }
        }
    return ans;
    }
};