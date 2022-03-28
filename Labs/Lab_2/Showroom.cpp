#include "Showroom.h"
    Showroom::Showroom() {
        name = "Unnamed Showroom";
        capacity = 0;
    }

    Showroom::Showroom(string inname, unsigned int incapacity) {
        name = inname;
        capacity = incapacity;
    }
    
    string Showroom::GetName() {
        return name;
    }

    vector<Vehicle> Showroom::GetVehicleList() {
       return vehicles;
    }

    void Showroom::AddVehicle(Vehicle v) {
        if (vehicles.size() < capacity) {
            vehicles.push_back(v);
        }
        else {
            cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
        }
        
    }

    void Showroom::ShowInventory() {
        if (vehicles.size()==0) {
            cout << name << " is empty!" << endl;
        }
        else {
            cout << "Vehicles in " << name << endl;
            for(int i = 0; i < (int)vehicles.size(); i += 1)
                vehicles.at(i).Display();
        }
    }

    float Showroom::GetInventoryValue() {
        float sum = 0;
        for(int i = 0; i < (int)vehicles.size(); i += 1) {
            sum += vehicles.at(i).GetPrice();
        }
        return sum;   
    }