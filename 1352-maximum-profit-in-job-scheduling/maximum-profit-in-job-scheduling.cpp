class Solution {
public:
    int t1[50001];
    int n;
    int nbi(vector<vector<int>>&a,int l,int target)
    {
      int r=n-1;
      int result=n+1;
      while(l<=r)
      {
        int mid = l+(r-l)/2;
        if(a[mid][0]>=target)
        {
        result=mid;
        r=mid-1;
        }
        else
        {
            l=mid+1;
        }
      }
      return result;
    }
    int f(vector<vector<int>>&a,int i)
    {
        if(i>=n)
        return 0;
        if(t1[i]!=-1)
        return t1[i];
        int next=nbi(a,i+1,a[i][1]);
        int t=a[i][2]+f(a,next);
        int nt=f(a,i+1);
        return t1[i]=max(t,nt);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
    n=st.size();
    memset(t1,-1,sizeof(t1));
    vector<vector<int>>a(n,vector<int>(3,0));
    for(int i=0;i<n;i++)
    {
        a[i][0]=st[i];
        a[i][1]=et[i];
        a[i][2]=p[i];
    }
    auto comp = [&](const vector<int>& vec1, const vector<int>& vec2) {
        return vec1[0] < vec2[0];
        };
    sort(a.begin(),a.end(),comp);
    return f(a,0);
    }
};