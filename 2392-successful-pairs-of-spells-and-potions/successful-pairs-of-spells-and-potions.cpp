#define ll long long 
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
    sort(potions.begin(),potions.end());
    int n=spells.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        ll sp=spells[i];
        ll l=0,h=potions.size()-1;
        int ind=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(potions[mid]*sp>=success)
            {
                ind=mid;
                h=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        ans[i]=(ind==-1)?0:(potions.size()-ind);
    }
    return ans;
    }
};