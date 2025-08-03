class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int sp, int k) {
    int n = fruits.size();
    vector<int>prefixsum(n);
    vector<int>indices(n);
    for(int i=0;i<n;i++)
    {
        indices[i]=fruits[i][0];
        prefixsum[i]=fruits[i][1]+(i>0? prefixsum[i-1]:0);
    }
    int maxi=0;
    for(int d=0;d<=k/2;d++)
    {
        int rem=k-2*d;
        int i= sp-d;
        int j=sp+rem;
        int l=lower_bound(indices.begin(),indices.end(),i)-indices.begin();
        int r=lower_bound(indices.begin(),indices.end(),j+1)-indices.begin()-1;
          if(l<=r)
          {
                int total = prefixsum[r]-(l>0?prefixsum[l-1] : 0);
                maxi = max(maxi,total);
           }
            i=sp-rem;
            j=sp+d; 
            l  = lower_bound(indices.begin(),indices.end(),i)-indices.begin();
            r = upper_bound(indices.begin(),indices.end(),j)-indices.begin()-1;
            if(l<=r) 
            {
                int total = prefixsum[r]-(l>0?prefixsum[l-1]:0);
                maxi = max(maxi,total);
            }
        }
        return maxi;
    }
};