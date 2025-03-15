//float karne ke liye 1.0 semulitply karo
#define ll long long
class Solution {
public:
    int f(int l ,int r ,vector<int>&p ,int minp)
    {
        int ans=-1;
        int mid=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(p[mid]>=minp)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, ll ss) {
    int m=s.size(),n=p.size();
    sort(p.begin(),p.end());
    int maxp=p[n-1];
    vector<int>ans;
    for(int i=0;i<m;i++)
    {
        int sp=s[i];
        ll minp=ceil((1.0*ss)/sp);
        if(minp>maxp)
        {
            ans.push_back(0);
            continue;
        }
        int ind=f(0,n-1,p,minp);
        int cnt= n-ind;
        ans.push_back(cnt);
        
    }
    return ans;
    }
};