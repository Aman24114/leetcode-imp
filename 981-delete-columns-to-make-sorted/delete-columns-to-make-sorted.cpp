class Solution {
public:
    int minDeletionSize(vector<string>& s) {
    int n=s.size();
    int m=s[0].size();
    int ans=0;
    for(int col=0;col<m;col++)
    {
        for(int row=1;row<n;row++)
        {
            if(s[row][col]<s[row-1][col])
            {
                ans++;
                break;
            }
        }
    }
    return ans;
    }
};