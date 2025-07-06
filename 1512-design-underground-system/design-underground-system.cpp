class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>cmap;
    unordered_map<string,pair<double,int>>rmap;
    UndergroundSystem()
    {}
    void checkIn(int id, string stationName, int t){
    cmap[id]={stationName,t};
    }
    void checkOut(int id, string stationName, int t){
    auto checkin=cmap[id];
    cmap.erase(id);
    string routename=checkin.first+"_"+stationName;
    rmap[routename].first+=t-checkin.second;
    rmap[routename].second+=1;
    }
    double getAverageTime(string startStation, string endStation){
    string routename = startStation + "_" + endStation;
    auto route = rmap[routename];
    return route.first / route.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */