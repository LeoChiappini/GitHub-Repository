#include  "Vehicle.h"
    Vehicle::Vehicle() {
        make = "COP3503";
        model = "Rust Bucket";
        year = 1900;
        price = 0;
        miles = 0;
    }

    Vehicle::Vehicle(string InMake, string InModel, int InYear, float InPrice, int InMiles) {
        make = InMake;
        model = InModel;
        year = InYear;
        price = InPrice;
        miles = InMiles;
    }

    // Prints out vehicle details in a single line. 1973 Ford Mustang $9500 113000
    void Vehicle::Display() {
        cout << year << " " << make << " " << model << " $" << price << " " << miles << endl;
    }

    // 1970 Ford Mustang
    string Vehicle::GetYearMakeModel(){
        // string ans = to_string(year) + " " + make + " " + model;
        return to_string(year) + " " + make + " " + model;
        //return year + " " + make + " " + model;
    }

    // Returns the price
    float Vehicle::GetPrice() {
        return price;
    }