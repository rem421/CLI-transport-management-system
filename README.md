# CLI Transport Management System

A command-line application for managing a vehicle transport fleet, written in C++. This project serves as a practical demonstration of Object-Oriented Programming (OOP) principles, including inheritance, polymorphism, and encapsulation.

## Features

* **Fleet Management:** Add, remove, and list all vehicles in the fleet.
* **Vehicle Inspection:** View detailed properties of any individual vehicle by its ID.
* **Object-Oriented Design:** Utilizes a C++ class hierarchy (e.g., `Bus` inheriting from `Vehicle`) to manage different vehicle types polymorphically.
* **Clean Code Structure:** Emphasizes separation of concerns with distinct header (`.h`) and implementation (`.cpp`) files.
* **Makefile Build System:** Includes a `Makefile` for streamlined compilation on Unix-like systems.

## Core Technologies

* **C++ (C++17)**
* **Make** (for the build system)

## Getting Started

Follow these steps to compile and run the project on your local machine.

### Prerequisites

You will need a C++ compiler and `make` installed.

* **On Debian/Ubuntu-based systems:**
    ```sh
    sudo apt-get install build-essential
    ```

### Compilation and Execution

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/rem421/CLI-transport-management-system.git](https://github.com/rem421/CLI-transport-management-system.git)
    ```

2.  **Navigate to the project directory:**
    ```sh
    cd CLI-transport-management-system
    ```

3.  **Compile the project using the `Makefile`:**
    ```sh
    make
    ```
    This command compiles the source code and creates an executable file named `transport_manager` in the same directory.

4.  **Run the application:**
    ```sh
    ./transport_manager
    ```

## Usage

Upon launching the application, you will be presented with an interactive menu to manage the fleet.

```
Welcome to the Transport Management System!
===========================================
1. Add a new vehicle
2. Remove a vehicle
3. Show all vehicles
4. Find vehicle by ID
5. Exit
===========================================
Enter your choice:
```

## Project Architecture

The application is designed using a clear object-oriented class structure:

* `Vehicle.h` / `Vehicle.cpp`: An **abstract base class** that defines the common interface and attributes (like `id`, `model`) for all vehicles.
* `Bus.h` / `Bus.cpp`: A **concrete derived class** that inherits from `Vehicle` and implements specific properties and behaviors related to a bus (e.g., `passenger_capacity`).
* `Transport.h` / `Transport.cpp`: The primary **manager class**. It holds the collection of all vehicles (e.g., in a `std::vector<std::unique_ptr<Vehicle>>`) and handles the main application logic for adding, removing, and finding vehicles.
* `main.cpp`: The application **entry point**. It contains the main loop, handles user input, and calls methods from the `Transport` class to perform operations.
* `Makefile`: Defines the build rules for compiling all source files and linking them into the final executable.

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

## Author

**Remigiusz Leśny**
