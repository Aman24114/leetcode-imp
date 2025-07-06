class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxi = 0;
    SeatManager(int n){
    }
    
    int reserve() {
    int res=0;
    if(pq.empty())
    {
        res=++maxi;
    }
    else
    {
        res=pq.top();
        pq.pop();
    }
    return res;
    }
    
    void unreserve(int seatNumber) {
    pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */