class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
    int ans=0;
    sort(p.rbegin(),p.rend());
    for(int i=0;i<p.size();i++)
    {
        int x1=p[i][0];
        int y1=p[i][1];
        for(int j=0;j<p.size();j++)
        {
            int x2=p[j][0];
            int y2=p[j][1];
            if(x1<=x2 && y1>=y2 &&(x1< x2 || y1>y2))
            {
                bool b= true;
                for(int k=0;k<p.size();k++)
                {
                    if(k==i ||k==j)
                    continue;
                    int x3=p[k][0];
                    int y3=p[k][1];
                    if(x1<=x3 && x3<=x2 && y1>=y3 && y3>=y2)
                    {
                        b=false;
                        break;
                    }
                }
                if(b)
                ans++;
            }

        }
    }
    return ans;
    }
};