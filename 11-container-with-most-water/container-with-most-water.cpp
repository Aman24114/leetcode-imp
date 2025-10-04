class Solution {
public:
    int maxArea(vector<int>& h) {
    int l=0;
    int r=h.size()-1;
    int maxi=0;
    while(l<r)
    {
        int curr=min(h[r],h[l])*(r-l);
        maxi=max(maxi,curr);
        if(h[l]<h[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }   
    return maxi;
    }
};