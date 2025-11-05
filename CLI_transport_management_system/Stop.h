#ifndef STOP_H
#define STOP_H

#include <unordered_map>
#include <ctime>
#include <string>
#include "Vehicle.h" // Include the Vehicle header file

class Stop {
public:
    int stopId;
    std::string name;
    std::unordered_map<Stop*, int> connections;
    std::unordered_map<time_t, Vehicle*> schedule;

    Stop(int id, const std::string& stopName);

    void addConnection(Stop* stop, int distance);
    void addSchedule(time_t time, Vehicle* vehicle);
};

#endif // STOP_H
