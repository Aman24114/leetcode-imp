class Router {
public:
    int MAX_SIZE;
    unordered_map<string,vector<int>>ps; // key={s,d,t};
    unordered_map<int, vector<int>> dts;// d-{t1,t2,t3};
    queue<string>q;
    Router(int memoryLimit) {
    MAX_SIZE=memoryLimit;   
    }
    string makekey(int s,int d,int t)
    {
        return to_string(s)+"_"+to_string(d)+"_"+to_string(t);
    }

    bool addPacket(int source, int destination, int timestamp) {
    string key=makekey(source,destination,timestamp);
    if(ps.find(key)!=ps.end())
    {
        return false;
    }
    if(q.size()>=MAX_SIZE)
    {
       forwardPacket();
    }
    ps[key]={source,destination,timestamp};
    q.push(key);
    dts[destination].push_back(timestamp);
    return true;
    }
    
    vector<int> forwardPacket() {
    if(ps.empty())
    {
        return {};
    }
    string key=q.front();
    q.pop();
    vector<int>packet=ps[key];
    ps.erase(key);
    int d=packet[1];
    dts[d].erase(dts[d].begin());
    return packet;
    }
    
    int getCount(int des, int st, int et) {
    auto it = dts.find(des);
    if (it == dts.end() || it->second.empty()) 
    return 0;
    int i = lower_bound(begin(it->second), end(it->second), st) - begin(it->second);
    int j = upper_bound(begin(it->second), end(it->second), et) - begin(it->second);
    return j - i;
    }
};