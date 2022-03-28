#pragma once
#include "Vehicle.h"
class Showroom {
    private:
        string name;
        vector<Vehicle> vehicles;
        unsigned int capacity;
    
    public:
        Showroom();

        Showroom(string name, unsigned int capacity);

        string GetName();

        vector<Vehicle> GetVehicleList();

        void AddVehicle(Vehicle v);

        void ShowInventory();

        float GetInventoryValue();
};