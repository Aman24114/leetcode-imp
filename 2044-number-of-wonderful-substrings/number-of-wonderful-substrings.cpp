class Solution {
public:
    typedef long long ll;
    ll wonderfulSubstrings(string word)
    {
      unordered_map<ll,ll>mp;
      mp[0]=1;
      ll cumxor=0;
      ll result=0;
      for(auto it:word)
      {
        int shift=it-'a';
        cumxor^=(1<<shift);
        result+=mp[cumxor];
        for(int ch='a';ch<='j';ch++)
        {
            shift=ch-'a';
            ll checkxor=cumxor^(1<<shift);
            result+=mp[checkxor];
        }
        mp[cumxor]++;
      }
      return result;
    }
};