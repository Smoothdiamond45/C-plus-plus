#ifndef DRIVERS_H
#define DRIVERS_H

#include <string>
#include <iomanip>
using namespace std;

enum LicenseTypes {
    D = 1,   // Regular taxi license
    D1 = 2,  // Minibus license
    B = 3    // Standard car license
};

// In Drivers.h
class Drivers {
private:
    string driversID;
    int phoneNumber;
    int taxiMileage;
    unsigned short licenseType;
    bool driverAvailability;
    float driversFare;

public:
     Drivers(string driversID, int phoneNumber, int taxiMileage,
        unsigned short licenseType, bool driverAvailability, float driversFare);
    // Getters
    string getDriversID() const { return driversID; }
    int getPhoneNumber() const { return phoneNumber; }
    int getTaxiMileage() const { return taxiMileage; }
    unsigned short getLicenseType() const { return licenseType; }
    bool isAvailable() const { return driverAvailability; }
    float getDriversFare() const { return driversFare; }

    // Setters
    void setDriversID(string id) { driversID = id; }
    void setPhoneNumber(int number) { phoneNumber = number; }
    void setTaxiMileage(int mileage) { taxiMileage = mileage; }
    void setLicenseType(unsigned short type) { licenseType = type; }
    void setAvailability(bool available) { driverAvailability = available; }
    void setDriversFare(float fare) { driversFare += fare; }
};
#endif
