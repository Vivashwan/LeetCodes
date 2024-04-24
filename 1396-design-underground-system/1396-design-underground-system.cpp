class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>>mp;
    unordered_map<string, pair<double, int>>route;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = mp[id];

        mp.erase(id);

        string routeName = checkIn.first+"_"+stationName;

        route[routeName].first += t - checkIn.second;
        route[routeName].second+=1;

    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation+"_"+endStation;

        auto value = route[routeName];

        return value.first/value.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */