class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int es) {
    priority_queue<pair<double,pair<int,int>>>pq;
    int n = c.size();
    for(int i=0;i<n;i++)
    {
        int a=c[i][0];
        int b=c[i][1];
        double gain=(double)(a+1)/(b+1)-(double)a/b;
        pq.push({gain,{a,b}});
    }
    while(es--)
    {
        auto it=pq.top();
        pq.pop();
        int a1=it.second.first;
        int b1=it.second.second;
        a1++;
        b1++;
        double gain=(double)(a1+1)/(b1+1)-(double)a1/b1;
        pq.push({gain,{a1,b1}});
    }
    double sum=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int a=it.second.first;
        int b=it.second.second;
        sum+=(double)a/(double)b;
    }
    return sum/n;
    }
};