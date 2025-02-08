#ifndef DISPATCHSYSTEM_H
#define DISPATCHSYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include "Vehicles.h"
#include "Drivers.h"

using namespace std;


class DispatchSystem {
private:
    vector<Vehicles> vehicles;
    vector<Drivers> drivers;
    vector<pair<int, int>> activeBookings;


public:
    DispatchSystem();
    void displayMenu();
    void printAllVehiclesandDrivers();
    void printBookedVehiclesAndDrivers();
    void makeBooking();
    void completeFare();
    void initializeVehicles();
    void initializeDrivers();
    bool isVehicleAvailable(int vehicleId);
    bool isDriverAvailable(int driverId);
    bool hasValidLicense(const Drivers& driver, const Vehicles& vehicle);
};

#endif
