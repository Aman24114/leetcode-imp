
class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int>t;
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end());
        priority_queue<int,vector<int>,greater<int>>free;
        for (int i=0;i<n;++i)
        {
            free.push(i);
        }
        priority_queue<t,vector<t>,greater<t>>busy;
        vector<int>cnt(n, 0);
        for (auto& m:meetings) {
            ll s = m[0];
            ll e = m[1];
            while (!busy.empty()&& busy.top().first<=s)
            {
                free.push(busy.top().second);
                busy.pop();
            }
            int room;
            ll  newend;
            if (!free.empty())
            {
                room = free.top();
                free.pop();
                newend = e;
            } 
            else
            {
                auto[end,r]=busy.top();
                busy.pop();
                room = r;
                newend = end+(e-s);
            }
            busy.emplace(newend, room);
            ++cnt[room];
        }
        return int(max_element(cnt.begin(), cnt.end()) - cnt.begin());
    }
};