#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    int vehicleId;
    std::string vehicleType;

    Vehicle(int id, const std::string& type);
};

#endif // VEHICLE_H
