#ifndef VEHICLES_H
#define VEHICLES_H
#include <string>
using namespace std;

class Vehicles {
private:
    int vehicleID;
    string vehicleType;
    string vehicleReg;
    string vehicleMake;
    string vehicleModel;
    int numberOfMiles;
    int numberOfPeople;
    bool vehicleInUse;
    float vehicleFare;

public:
   Vehicles(int vehicleID, string vehicleType, string vehicleReg,string vehicleMake, string vehicleModel,int numberOfMiles, int numberOfPeople,
       bool vehicleInUse, float vehicleFare);
    // Getters
    int getVehicleID() const { return vehicleID; }
    string getVehicleType() const { return vehicleType; }
    string getVehicleReg() const { return vehicleReg; }
    string getVehicleMake() const { return vehicleMake; }
    string getVehicleModel() const { return vehicleModel; }
    int getNumberOfMiles() const { return numberOfMiles; }
    int getNumberOfPeople() const { return numberOfPeople; }
    bool isInUse() const { return vehicleInUse; }
    float getVehicleFare() const { return vehicleFare; }

    // Setters
    void setVehicleID(int id) { vehicleID = id; }
    void setVehicleType(string type) { vehicleType = type; }
    void setVehicleReg(string reg) { vehicleReg = reg; }
    void setVehicleMake(string make) { vehicleMake = make; }
    void setVehicleModel(string model) { vehicleModel = model; }
    void setNumberOfMiles(int miles) { numberOfMiles = miles; }
    void setNumberOfPeople(int people) { numberOfPeople = people; }
    void setInUse(bool inUse) { vehicleInUse = inUse; }
    void setVehicleFare(float fare) { vehicleFare += fare; }
};
#endif
