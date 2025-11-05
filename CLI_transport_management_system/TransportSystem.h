#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include <unordered_map>
#include <vector>
#include <ctime>
#include <iostream>
#include <queue>
#include "Stop.h" // Include the Stop header file

class TransportSystem {
public:
    std::unordered_map<int, Stop*> stops;
    std::unordered_map<int, Vehicle*> vehicles;

    void addStop(int stopId, const std::string& stopName);
    void addVehicle(int vehicleId, const std::string& vehicleType);
    void addConnection(int stopId1, int stopId2, int distance);
    void addSchedule(int stopId, time_t time, int vehicleId);
    void searchConnections(int startStopId, int endStopId);

private:
    std::vector<Stop*> findConnections(int startStopId, int endStopId);
    void bfs(Stop* startStop, Stop* endStop, std::unordered_map<Stop*, bool>& visited,
             std::vector<Stop*>& currentPath, std::vector<std::vector<Stop*>>& allPaths);
};

#endif // TRANSPORTSYSTEM_H
