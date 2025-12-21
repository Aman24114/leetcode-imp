class Solution {
public:
    int minDeletionSize(vector<string>& s) {
    int n=s.size();
    int m=s[0].size();
    vector<bool>sort(n-1,false);
    int ans=0;
    for(int j=0;j<m;j++)
    {
        bool b=false;
        for(int i=0;i<n-1;i++)
        {
            if(!sort[i] && s[i][j]>s[i+1][j])
            {
                b=true;
                break;
            }
        }
        if(b)
        {
            ans++;
            continue;
        }
        for(int i=0;i<n-1;i++)
        {
            if(!sort[i] && s[i][j]<s[i+1][j])
            sort[i]=true;
        }
    }
    return ans;
    }
};