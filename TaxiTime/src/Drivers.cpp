#include "Drivers.h"
#include <iostream>

// Constructor implementation
Drivers::Drivers(std::string driversID, int phoneNumber, int taxiMileage,
                unsigned short licenseType, bool driverAvailability, float driversFare)
{
    this->driversID = driversID;
    this->phoneNumber = phoneNumber;
    this->taxiMileage = taxiMileage;
    this->licenseType = licenseType;
    this->driverAvailability = driverAvailability;
    this->driversFare = driversFare;
}
