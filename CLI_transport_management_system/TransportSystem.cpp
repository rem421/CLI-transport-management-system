#include "TransportSystem.h"

void TransportSystem::addStop(int stopId, const std::string& stopName) {
    if (stops.find(stopId) == stops.end()) {
        stops[stopId] = new Stop(stopId, stopName);
        std::cout << "Stop added: " << stopName << std::endl;
    } else {
        std::cout << "Stop with ID " << stopId << " already exists." << std::endl;
    }
}

void TransportSystem::addVehicle(int vehicleId, const std::string& vehicleType) {
    if (vehicles.find(vehicleId) == vehicles.end()) {
        vehicles[vehicleId] = new Vehicle(vehicleId, vehicleType);
        std::cout << "Vehicle added: " << vehicleType << std::endl;
    } else {
        std::cout << "Vehicle with ID " << vehicleId << " already exists." << std::endl;
    }
}

void TransportSystem::addConnection(int stopId1, int stopId2, int distance) {
    if (stops.find(stopId1) != stops.end() && stops.find(stopId2) != stops.end()) {
        Stop* stop1 = stops[stopId1];
        Stop* stop2 = stops[stopId2];
        stop1->addConnection(stop2, distance);
        std::cout << "Connection added between stops " << stop1->name << " and " << stop2->name << std::endl;
    } else {
        std::cout << "One or more stops not found." << std::endl;
    }
}

void TransportSystem::addSchedule(int stopId, time_t time, int vehicleId) {
    if (stops.find(stopId) != stops.end() && vehicles.find(vehicleId) != vehicles.end()) {
        Stop* stop = stops[stopId];
        Vehicle* vehicle = vehicles[vehicleId];
        stop->addSchedule(time, vehicle);
        std::cout << "Schedule added for stop " << stop->name << " at " << ctime(&time);
    } else {
        std::cout << "Stop or vehicle not found." << std::endl;
    }
}

void TransportSystem::searchConnections(int startStopId, int endStopId) {
    std::vector<Stop*> connections = findConnections(startStopId, endStopId);
    if (!connections.empty()) {
        std::cout << "Connections:";
        for (auto stop : connections) {
            std::cout << " " << stop->name;
        }
        std::cout << std::endl;
    } else {
        std::cout << "Stops not found." << std::endl;
    }
}

std::vector<Stop*> TransportSystem::findConnections(int startStopId, int endStopId) {
    std::vector<Stop*> connections;
    if (stops.find(startStopId) != stops.end() && stops.find(endStopId) != stops.end()) {
        Stop* startStop = stops[startStopId];
        Stop* endStop = stops[endStopId];

        std::unordered_map<Stop*, bool> visited;
        std::vector<std::vector<Stop*>> allPaths;
        std::vector<Stop*> currentPath;

        bfs(startStop, endStop, visited, currentPath, allPaths);

        if (!allPaths.empty()) {
            connections = allPaths.front();
        }
    }

    return connections;
}

void TransportSystem::bfs(Stop* startStop, Stop* endStop, std::unordered_map<Stop*, bool>& visited,
                          std::vector<Stop*>& currentPath, std::vector<std::vector<Stop*>>& allPaths) {
    std::queue<std::vector<Stop*>> queue;
    visited[startStop] = true;
    currentPath.push_back(startStop);
    queue.push(currentPath);

    while (!queue.empty()) {
        currentPath = queue.front();
        queue.pop();
        Stop* currentStop = currentPath.back();

        if (currentStop == endStop) {
            allPaths.push_back(currentPath);
            continue;  // Continue to explore other paths
        }

        for (auto& neighbor : currentStop->connections) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                std::vector<Stop*> newPath = currentPath;
                newPath.push_back(neighbor.first);
                queue.push(newPath);
            }
        }
    }
}
