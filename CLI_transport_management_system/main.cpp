#include "TransportSystem.h"

int main() {
    TransportSystem transportSystem;

    while (true) {
        std::cout << "\nMenu:\n"
                     "1. Add Stop\n"
                     "2. Add Vehicle\n"
                     "3. Add Connection\n"
                     "4. Add Schedule\n"
                     "5. Search Connections\n"
                     "6. Exit\n"
                     "Enter your choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear();  // Clear the error state

            // Consume the entire line of input
            std::string invalidInput;
            std::getline(std::cin, invalidInput);
            
            continue;  // Skip the rest of the loop and prompt again
        }

        switch (choice) {
            case 1: {
                int stopId;
                std::string stopName;
                std::cout << "Enter Stop ID: ";
                std::cin >> stopId;
                std::cout << "Enter Stop Name: ";
                std::cin >> stopName;
                transportSystem.addStop(stopId, stopName);
                break;
            }
            case 2: {
                int vehicleId;
                std::string vehicleType;
                std::cout << "Enter Vehicle ID: ";
                std::cin >> vehicleId;
                std::cout << "Enter Vehicle Type: ";
                std::cin >> vehicleType;
                transportSystem.addVehicle(vehicleId, vehicleType);
                break;
            }
            case 3: {
                int stopId1, stopId2, distance;
                std::cout << "Enter Stop 1 ID: ";
                std::cin >> stopId1;
                std::cout << "Enter Stop 2 ID: ";
                std::cin >> stopId2;
                std::cout << "Enter Distance: ";
                std::cin >> distance;
                transportSystem.addConnection(stopId1, stopId2, distance);
                break;
            }
            case 4: {
                int stopId, vehicleId;
                time_t time;
                std::cout << "Enter Stop ID: ";
                std::cin >> stopId;
                std::cout << "Enter Time (in seconds since epoch): ";
                std::cin >> time;
                std::cout << "Enter Vehicle ID: ";
                std::cin >> vehicleId;
                transportSystem.addSchedule(stopId, time, vehicleId);
                break;
            }
            case 5: {
                int startStopId, endStopId;
                std::cout << "Enter Start Stop ID: ";
                std::cin >> startStopId;
                std::cout << "Enter End Stop ID: ";
                std::cin >> endStopId;
                transportSystem.searchConnections(startStopId, endStopId);
                break;
            }
            case 6: {
                std::cout << "Exiting program.\n";
                return 0;
            }
                
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                std::cin.clear();  // Clear the error state
                break;
            }                
        }
    }

    return 0;
}