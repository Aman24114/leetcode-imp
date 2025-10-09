#define ll long long 
class Solution {
public:
    ll minTime(vector<int>& skills, vector<int>& mana){
    int n=skills.size(); // n wizards 
    int m=mana.size(); // m potions
    vector<ll>ft(n,0);
    for(int j=0;j<m;j++)
    {
        ft[0]+=mana[j]*skills[0];
        for(int i=1;i<n;i++)
        {
            ft[i]=max(ft[i],ft[i-1])+1LL*mana[j]*skills[i];
        }
        for(int i=n-1;i>0;i--)
        {
            ft[i-1]=ft[i]-1LL*mana[j]*skills[i];
        }
    }    
    return ft[n-1];  
    }
};