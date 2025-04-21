#define ll long long 
class Solution {
public:
    int numberOfArrays(vector<int>& diff, int low, int upp)
    {
        ll pre=0;
        ll mini,maxi=0;
        for(auto &it:diff)
        {
          pre+=it;
          mini=min(mini,pre);
          maxi=max(maxi,pre);
        }     
        return max((ll)0,(upp-maxi-(low-mini))+1);
    }
};