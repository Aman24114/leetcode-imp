class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
    int n=events.size();
    sort(events.begin(),events.end());
    int ans=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    int k=0;
    for(int i=0;i<=1e5;i++)
    {
        // putting endtimes over here
        while(!pq.empty()&& pq.top()<i)
        {
           pq.pop();   
        }
        // jitna start hia yahan se sab daalo
        while(k<n && events[k][0]==i)
        {
           pq.push(events[k][1]);
           k++;
        }
        if(pq.empty())
        {
            continue;
        }
        ans+=1;
        pq.pop();
    }   
    return ans;
    }
};