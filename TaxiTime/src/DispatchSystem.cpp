#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <regex>
#include "Vehicles.h"
#include "Drivers.h"
#include "DispatchSystem.h"

using namespace std;
DispatchSystem::DispatchSystem() {




    initializeVehicles();
    initializeDrivers();
}
void DispatchSystem::printAllVehiclesandDrivers() {

    cout << "\nAll Drivers:\n";
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    cout << left  // align text to the left
         << setw(20) << "Drivers ID"
         << setw(15) << "Phone Number"
         << setw(10) << "Mileage"
         << setw(15) << "License Type"
         << setw(15) << "Availability"
         << setw(10) << "Fare" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";

    for (const auto& driver : drivers) {
        cout << left // slide to the left
             << setw(20) << driver.getDriversID()
             << setw(15) << driver.getPhoneNumber()
             << setw(10) << driver.getTaxiMileage()
             << setw(15) << driver.getLicenseType()
             << setw(15) << (driver.isAvailable() ? "Available" : "Booked")
             << setw(10) << driver.getDriversFare() << endl;
    }
    cout << "\nAll Vehicles:\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << left // and again
         << setw(8) << "ID"
         << setw(12) << "Type"
         << setw(15) << "Reg"
         << setw(15) << "Make"
         << setw(15) << "Model"
         << setw(10) << "Miles"
         << setw(10) << "Fare"
         << "Status" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------\n";

    for (const auto& vehicle : vehicles) {
        cout << left // and again....
             << setw(8) << vehicle.getVehicleID()
             << setw(12) << vehicle.getVehicleType()
             << setw(15) << vehicle.getVehicleReg()
             << setw(15) << vehicle.getVehicleMake()
             << setw(15) << vehicle.getVehicleModel()
             << setw(10) << vehicle.getNumberOfMiles()
             << setw(10) << fixed << setprecision(2) << vehicle.getVehicleFare()




             << (vehicle.isInUse() ? "Booked" : "Available")
             << endl;
}}
void DispatchSystem::printBookedVehiclesAndDrivers(){
cout << "----------------------------------------------------------------------------------------------------------------------\n";
    cout << left  //im getting sick of this
         << setw(20) << "Drivers ID"
         << setw(15) << "Phone Number"
         << setw(10) << "Mileage"
         << setw(15) << "License Type"
         << setw(15) << "Availability"
         << setw(10) << "Fare" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    // i hate how all i had to do was add one line.....
    for (const auto& driver : drivers) {
    if (!driver.isAvailable()){ // <- this is the one line
        cout << left // never ends
             << setw(20) << driver.getDriversID()
             << setw(15) << driver.getPhoneNumber()
             << setw(10) << driver.getTaxiMileage()
             << setw(15) << driver.getLicenseType()
             << setw(15) << driver.isAvailable()
             << setw(10) << driver.getDriversFare() << endl;
             }
    }
    }


void DispatchSystem::initializeVehicles() {
    vehicles = {  // Creates an array of Vehicles that are rusting away or getting stolen
    Vehicles(1, "Taxi", "241-C-4956", "Hyundai", "i30",     0, 4, false, 0.0),
    Vehicles(2, "Taxi", "242-C-2365", "Ford", "Mondeo",     0, 4, false, 0.0),
    Vehicles(3, "Taxi", "251-C-1256", "VW", "Passat",       0, 4, false, 0.0),
    Vehicles(4, "Taxi", "181-C-38492", "Nissan", "Primera", 0, 4, false, 0.0),
    Vehicles(5, "Taxi", "202-C-99393", "Skoda", "Octavia",  0, 4, false, 0.0),
    Vehicles(6, "Taxi", "222-C-2379", "Seat", "Toledo",     0, 4, false, 0.0),
    Vehicles(7, "Minibus", "192-C-87908", "Ford", "Transit",0, 16, false, 0.0),
    Vehicles(8, "Minibus", "211-C-831", "Fiat", "Ducato",   0, 16, false, 0.0),
    Vehicles(9, "Minibus", "231-C-82677", "Merc", "Vario",  0, 16, false, 0.0),
    Vehicles(10, "Bus", "10-C-37209", "Ace", "Cougar",      0, 48, false, 0.0),
    Vehicles(11, "Bus", "182-C-882", "Daimler", "Fleet",    0, 48, false, 0.0)

    };
}
void DispatchSystem::initializeDrivers() {
        drivers = {
        // all the pesky drivers just slacking off
        Drivers ("Tom daly", 876543210, 23231, B, true, 0.0),
        Drivers ("Anne O'Brien",865432109,11980, D, true, 0.0),
        Drivers ("James Twomey", 854321098, 18414, D1, true, 0.0),
        Drivers ("Mary O'Neil", 898765432, 12669, B, true, 0.0),
        Drivers ("Brendan Brown", 832109876, 23864,D, true, 0.0),
        Drivers ("Vincent Coy", 878901234, 34196,D1, true, 0.0)
        };
}
bool DispatchSystem::isVehicleAvailable(int vehicleId) {
    // Simple loop through vehicles array
    for (int i = 0; i < vehicles.size(); i++) {
        if (vehicles[i].getVehicleID() == vehicleId) {
            return !vehicles[i].isInUse();
        }
    }
    return false;  // Vehicle not found (probably stolen)
}

bool DispatchSystem::isDriverAvailable(int driverId) {
    // Simple loop through drivers array
    for (int i = 0; i < drivers.size(); i++) {
        if (drivers[i].getPhoneNumber() == driverId) {
            return drivers[i].isAvailable();
        }
    }
    return false;  // Driver not found cus hes probably napping
}

bool DispatchSystem::hasValidLicense(const Drivers& driver, const Vehicles& vehicle) {
    // Get the type of vehicle and the driver's license type
    string vehicleType = vehicle.getVehicleType();
    int licenseType = driver.getLicenseType();

    if (vehicleType == "Bus") {
        // Only drivers with D license can drive buses duh
        return (licenseType == D);
    }

    if (vehicleType == "Minibus") {
        // Drivers with either D1 or D license can drive minibuses again duh
        return (licenseType == D1 || licenseType == D);
    }

    if (vehicleType == "Taxi") {
        // Drivers with all three licenses can drive taxis duh
        return (licenseType == B || licenseType == D1 || licenseType == D);
    }
    return false;
}

void DispatchSystem::makeBooking() {
 // # original code still surviving
    int numberOfPeople;
    cout << "Welcome, how many people are traveling? ";

    while (!(cin >> numberOfPeople) || numberOfPeople <= 0 || numberOfPeople > 48) {
        cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number between 1 and 48: ";
    }
    // if statements are my true love
    string requiredVehicleType;
    if (numberOfPeople <= 4) {
        requiredVehicleType = "Taxi";
    } else if (numberOfPeople <= 16) {
        requiredVehicleType = "Minibus";
    } else {
        requiredVehicleType = "Bus";
    }
    // all i can think about is vector from despicable me, thats the true vector
    vector<Vehicles*> availableVehicles;
    for (auto& vehicle : vehicles) {
        if (vehicle.getVehicleType() == requiredVehicleType && !vehicle.isInUse()) {
            availableVehicles.push_back(&vehicle);
        }
    }

    if (availableVehicles.empty()) {
        cout << "Sorry, no available " << requiredVehicleType << "s at the moment.\n";
        return; //<- see being polite again, extra marks?
    }
    // disgusting
    cout << "\nAvailable " << requiredVehicleType << "s:\n";
    for (size_t i = 0; i < availableVehicles.size(); i++) {
        cout << i + 1 << ". " << availableVehicles[i]->getVehicleMake() << " "
             << availableVehicles[i]->getVehicleModel() << " ("
             << availableVehicles[i]->getVehicleReg() << ")\n";
    }

    int vehicleChoice;
    do {
        cout << "\nSelect vehicle (1-" << availableVehicles.size() << "): ";
        cin >> vehicleChoice;
    } while (vehicleChoice < 1 || vehicleChoice > availableVehicles.size());

    Vehicles* selectedVehicle = availableVehicles[vehicleChoice - 1];

    vector<Drivers*> availableDrivers;
    for (auto& driver : drivers) {
        if (driver.isAvailable() && hasValidLicense(driver, *selectedVehicle)) {
            availableDrivers.push_back(&driver);
        }
    }
    // empty means no driver for you, guess they gotta walk
    if (availableDrivers.empty()) {
        cout << "Sorry, no available drivers qualified for this vehicle type.\n";
        return; // <- so polite of me
    }

    cout << "\nAvailable Drivers:\n";
    for (size_t i = 0; i < availableDrivers.size(); i++) {
        cout << i + 1 << ". ID: " << availableDrivers[i]->getDriversID() << "\n";
    }

    int driverChoice;
    do {
        cout << "\nSelect driver (1-" << availableDrivers.size() << "): ";
        cin >> driverChoice;
    } while (driverChoice < 1 || driverChoice > availableDrivers.size());

    Drivers* selectedDriver = availableDrivers[driverChoice - 1];
    // getting those vehicles and drivers selected and pointed
    selectedVehicle->setInUse(true);
    selectedDriver->setAvailability(false);

    activeBookings.push_back({selectedVehicle->getVehicleID(), selectedDriver->getPhoneNumber()});

    cout << "\nBooking Confirmed!\n";
    cout << "Vehicle: " << selectedVehicle->getVehicleMake() << " "
         << selectedVehicle->getVehicleModel() << " ("
         << selectedVehicle->getVehicleReg() << ")\n";
    cout << "Driver: " << selectedDriver->getDriversID() << "\n";
    double vehicleCost;
    bool distanceisgood;
    string distancestringy;

    regex distancereggie ("\\d{1,3}");
    do {
    cout << "\nEnter travel distance:\n";
    cin >> distancestringy;
    distanceisgood = regex_match (distancestringy, distancereggie) && stoi (distancestringy) >=1;
    if (!distanceisgood) {
        cout <<"Please enter a valid distance, no letters no crazy level numbers\n";
        }
    }while (!distanceisgood);{
    //lets go best part
    if (selectedVehicle->getVehicleType() == "Taxi"){
    vehicleCost = 1.32;

    }else if (selectedVehicle->getVehicleType() == "Minibus"){
    vehicleCost = 6.78;

    } else if (selectedVehicle->getVehicleType() == "Bus"){
    vehicleCost = 10.99;
    }
    float estimatedFare = 4.40 + (vehicleCost *stoi(distancestringy));
    selectedVehicle->setVehicleFare(estimatedFare);
    selectedDriver->setDriversFare(estimatedFare);
    // getting paid just to clarify

    cout << "\nEstimated fare: $" << fixed << setprecision(2) << estimatedFare << endl;
    cout << "Your booking reference number is: " << activeBookings.size() << endl;
}}
//welcome to complete (nightmare) booking
void DispatchSystem::completeFare() {
    if (activeBookings.empty()) {
        cout << "No active bookings to complete.\n";
        return;
    }

    auto start = std::chrono::system_clock::now();

    // Display active mcbookings
    cout << "\nActive Bookings:\n";
    cout << "-------------------------------------------------------\n";
    for (size_t i = 0; i < activeBookings.size(); i++) {
        cout << i + 1 << ". ";
        for (const auto& vehicle : vehicles) {
            if (vehicle.getVehicleID() == activeBookings[i].first) {
                cout << vehicle.getVehicleMake() << " " << vehicle.getVehicleModel()
                     << " (" << vehicle.getVehicleReg() << ") - Fare: $"
                     << fixed << setprecision(2) << vehicle.getVehicleFare() << "\n";
            }
        }
    }

    // Get booking mcstuff
    int bookingChoice;
    cout << "\nSelect booking to complete (1-" << activeBookings.size() << "): ";
    while (!(cin >> bookingChoice) || bookingChoice < 1 || bookingChoice > activeBookings.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid booking number: ";
    }

    // Process payment, make it look crisp
    long long creditCardNumber;
    cout << "Enter the credit card number: ";
    while (!(cin >> creditCardNumber)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid credit card number: ";
    }
    string CustomerName;
    cout << "Please enter the Customers Name: ";
    cin >> CustomerName;

    // Get the booking detail stuff
    int vehicleId = activeBookings[bookingChoice - 1].first;
    int driverId = activeBookings[bookingChoice - 1].second;

    // Find the vehicle and pesky driver
    Vehicles* selectedVehicle = nullptr;
    Drivers* selectedDriver = nullptr;

    for (auto& vehicle : vehicles) {
        if (vehicle.getVehicleID() == vehicleId) {
            selectedVehicle = &vehicle;
            break;
        }
    }

    for (auto& driver : drivers) {
        if (driver.getPhoneNumber() == driverId) {
            selectedDriver = &driver;
            break;
        }
    }
    //displaying this dumb time
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    if (selectedVehicle && selectedDriver) {
        // Print receipt
        cout << "\nPayment Details:\n";
        cout << "-------------------------------------------------------\n";
        cout << "Customer name: " << CustomerName << "\n";
        cout << "Vehicle: " << selectedVehicle->getVehicleMake() << " "
             << selectedVehicle->getVehicleModel() << " ("
             << selectedVehicle->getVehicleReg() << ")\n";
        cout << "Driver: " << selectedDriver->getDriversID() << "\n";
        cout << "Fare Amount: $" << fixed << setprecision(2)
             << selectedVehicle->getVehicleFare() << "\n";
        cout << "Credit Card: XXXX-XXXX-XXXX-"
             << setw(4) << creditCardNumber % 10000 << "\n";
        cout << "finished computation at " << std::ctime(&end_time);
        cout << "-------------------------------------------------------\n";

    if (selectedVehicle) {
        selectedVehicle->setInUse(false);  //reset vehicle
    }

    // Reset that pesky driver
    if (selectedDriver) {
        selectedDriver->setAvailability(true);  // reset pesky driver

    }

    // Remove the booking from the list
    activeBookings.erase(activeBookings.begin() + (bookingChoice - 1));

    cout << "\nFare completed successfully!\n";
}
}
