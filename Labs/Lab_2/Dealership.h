#pragma once
#include "Showroom.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Dealership {
    private:
        string name;
        unsigned int capacity;
        vector<Showroom> rooms;

    public:
        Dealership();

        Dealership(string name, unsigned int capacity);

        void AddShowroom(Showroom s);

        float GetAveragePrice();

        void ShowInventory();
};