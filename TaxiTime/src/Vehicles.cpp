#include "Vehicles.h"
#include <iomanip>
#include <iostream>

using namespace std;

Vehicles::Vehicles(int vehicleID, string vehicleType, string vehicleReg,string vehicleMake, string vehicleModel,int numberOfMiles, int numberOfPeople,
bool vehicleInUse, float vehicleFare)

{
    this-> vehicleID = vehicleID;
    this-> vehicleType = vehicleType;
    this-> vehicleReg = vehicleReg;
    this-> vehicleMake = vehicleMake;
    this-> vehicleModel = vehicleModel;
    this-> numberOfMiles = numberOfMiles;
    this-> numberOfPeople = numberOfPeople;
    this-> vehicleInUse = vehicleInUse;
    this-> vehicleFare = vehicleFare;


}

