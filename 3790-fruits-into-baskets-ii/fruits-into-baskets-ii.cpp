class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n=fruits.size();
    int ans=0;
    vector<bool>v(n,false);
    for(int i=0;i<n;i++)
    {
        bool b=false;
        for(int  j=0;j<n;j++)
        {
            if(!v[j]&& baskets[j]>=fruits[i])
            {
                v[j]=true;
                b=true;
                break;
            }
        }
        if(b==false)
        {
            ans++;
        }
    }
    return ans;
    }
};