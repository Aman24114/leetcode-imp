class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
    vector<int>v(n,0);
    for(auto  &b1:b)
    {
        int l=b1[0];
        int r=b1[1];
        int s=b1[2];
        v[l-1]+=s;
        if(r<n)
        {
            v[r]-=s;
        }
    } 
    for(int i=1;i<n;i++)
    {
        v[i]+=v[i-1];
    }
    return v;   
    }
};