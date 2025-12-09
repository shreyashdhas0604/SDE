class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInData;      // id -> {startStation, time}
    unordered_map<string, pair<long long, int>> routeData;  // "start#end" -> {totalTime, count}

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = checkInData[id];
        string routeKey = checkInInfo.first + "#" + stationName;

        int travelTime = t - checkInInfo.second;

        routeData[routeKey].first += travelTime;  // Total time update
        routeData[routeKey].second++;             // Trip count update

        checkInData.erase(id);  // Remove customer as checked out
    }

    double getAverageTime(string startStation, string endStation) {
        string routeKey = startStation + "#" + endStation;
        auto &info = routeData[routeKey];
        return (double)info.first / info.second;
    }
};
