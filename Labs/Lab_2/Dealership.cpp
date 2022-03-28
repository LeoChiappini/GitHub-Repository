#include "Dealership.h"
    Dealership::Dealership(){
        name = "Generic Dealership";
        capacity = 0;
    }

    Dealership::Dealership(string Inname, unsigned int Incapacity){
        name = Inname;
        capacity = Incapacity;
        cout << name << " and " << capacity << endl;
    }

   void Dealership::AddShowroom(Showroom s) {
        cout << capacity << endl;
        if (rooms.size() == capacity) {
            cout << "Dealership is full, can't add another showroom!" << endl;
        }
        else
            rooms.push_back(s);
    }

    float Dealership::GetAveragePrice() {
        int cars = 0;
        float prices = 0;
        for(Showroom room : rooms) {
            cars += room.GetVehicleList().size();
            prices += room.GetInventoryValue();
        }
        if (prices == 0)
            return 0;
        return prices / (float)cars;
    }

    void Dealership::ShowInventory() {
        if (rooms.size() == 0)
            cout << name << " is empty!" << endl;;
        for (Showroom room: rooms) {
            room.ShowInventory();
            cout << endl;
        }
        cout << "Average car price: $" << GetAveragePrice();
    }