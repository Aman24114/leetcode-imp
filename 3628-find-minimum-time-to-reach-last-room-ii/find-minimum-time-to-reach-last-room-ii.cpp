class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    int minTimeToReach(vector<vector<int>>& movetime)
    {
      int n=movetime.size();
      int m=movetime[0].size();
      vector<vector<int>>time(n,vector<int>(m,INT_MAX));
     priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>> pq;
      pq.push({0,{1,{0,0}}});
      while(!pq.empty())
      {
        auto it=pq.top();
        int t=it.first;
        int c=it.second.first;
        int row=it.second.second.first;
        int col=it.second.second.second;
        pq.pop();
        for(int k=0;k<4;k++)
        {
            int newrow=row+dr[k];
            int newcol=col+dc[k];
            if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && time[newrow][newcol]>(c+max(t,movetime[newrow][newcol])))
            {
                time[newrow][newcol]=(c+max(t,movetime[newrow][newcol]));
                pq.push({time[newrow][newcol],{c==1?2:1,{newrow,newcol}}});
            }
        }
      }
      return time[n-1][m-1];
    }
};