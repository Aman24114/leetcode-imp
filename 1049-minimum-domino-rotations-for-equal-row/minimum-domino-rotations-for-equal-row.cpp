class Solution {
public:
    int f(int t,vector<int>tops,vector<int>bottoms)
    {
          int rt=0,rb=0;
          for(int i=0;i<tops.size();i++)
          {
            if(tops[i]!=t && bottoms[i]!=t)
            {
                return -1;
            }
            if(tops[i]!=t)
            {
                rt++;
            }
            if(bottoms[i]!=t)
            {
                rb++;
            }
          }
          return min(rt,rb);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int ans1=f(tops[0],tops,bottoms);
        int ans2=f(bottoms[0],tops,bottoms);
        if(ans1==-1)
        {
            return ans2;
        }
        else if(ans2==-1)
        {
            return ans1;
        }
        else
        {
            return min(ans1,ans2);
        }
    }
};