#include "Stop.h"

Stop::Stop(int id, const std::string& stopName) : stopId(id), name(stopName) {}

void Stop::addConnection(Stop* stop, int distance) {
    connections[stop] = distance;
    stop->connections[this] = distance;
}

void Stop::addSchedule(time_t time, Vehicle* vehicle) {
    schedule[time] = vehicle;
}
