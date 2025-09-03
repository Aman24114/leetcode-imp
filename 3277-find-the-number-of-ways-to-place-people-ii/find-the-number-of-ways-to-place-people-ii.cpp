class Solution {
public:
    bool f(int p1,int p2,vector<vector<int>>&p)
    {
        int n=p.size();
        int x1=p[p1][0];
        int y1=p[p1][1];
        int x2=p[p2][0];
        int y2=p[p2][1];
        for(int k=p2+1;k<p1;k++)
        {
            int x=p[k][0];
            int y=p[k][1];
            if(x<=x1 && x>=x2  && y>=y1 &&  y<=y2)
            return false;
        }
        return true;
    }
    bool static comp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]==v2[0])
        return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    int numberOfPairs(vector<vector<int>>& p) {
    int n=p.size();
    int ans=0;
    sort(p.begin(),p.end(),comp);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i==j)
            continue;
            int x1=p[i][0];
            int y1=p[i][1];
            int x2=p[j][0];
            int y2=p[j][1];
            if(y2>=y1 && f(i,j,p))
            ans++;
        }
    }
    return ans;
    }
};