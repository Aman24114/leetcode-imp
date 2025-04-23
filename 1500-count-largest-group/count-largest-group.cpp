class Solution {
public:
    int f(int i)
    {   int sum=0;
        while(i>0)
        { 
          sum+=i%10;
          i=i/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
    unordered_map<int,int>mp;
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        int dig=f(i);
        mp[dig]++;
        maxi=max(maxi,mp[dig]);
    }
    int cnt=0;
    for(auto it:mp)
    {
        if(it.second==maxi)
        cnt++;
    }   
    return cnt;
    }
};