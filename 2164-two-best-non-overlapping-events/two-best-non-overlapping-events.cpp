class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(),events.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int ans=0,maxi=0;
    for(auto it:events)
    {
        int s=it[0],e=it[1],val=it[2];
        while(!pq.empty() && pq.top().first<s)
        {
            maxi=max(maxi,pq.top().second);
            pq.pop();
        }
        ans=max(ans,maxi+val);
        pq.push({e,val});
    }
    return ans;
    }
};