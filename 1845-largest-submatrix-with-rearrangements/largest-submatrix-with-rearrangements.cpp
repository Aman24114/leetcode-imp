class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    int maxi=0;
    vector<int>prevh(n,0);
    for(int row=0;row<m;row++)
    {   
        vector<int>currh=matrix[row];
        for(int col=0;col<n;col++)
        {
            if(currh[col]==1)
            {
                currh[col]+=prevh[col];
            }
        }
        vector<int>h=currh;
        sort(h.rbegin(),h.rend()); 
        for(int i=0;i<n;i++)
        {
            int base=(i+1);
            int h1=h[i];
            maxi=max(maxi,base*h1);
        }
        prevh=currh;
    }
    return maxi;
    }
};