#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Weapon {

        // Weapon Properties
        string weaponName;
        int weaponInt;
        float weaponFloat;

        // Constructor
        Weapon(string nameIn, int intIn, float floatIn) {
            weaponName = nameIn;
            weaponInt = intIn;
            weaponFloat = floatIn;
        }

        // Outputs weapon information
        void printWeapon() {
            cout << weaponName << ", " << weaponInt << ", " << weaponFloat << endl;
        }
    };

struct Ship {
	
    // Ship Properties
    string name;
    string shipClass;
    short length;
    int shield;
    float warpSpeed;

    // Weapon Properties
    vector<Weapon> armament;

    // Constructor
	Ship(string nameIn, string classIn, short lengthIn, int shieldIn, float warpIn) {
		name = nameIn;
        shipClass = classIn;
        length = lengthIn;
        shield = shieldIn;
        warpSpeed = warpIn;
	}

    int calculateFirepower() {
        int sum = 0;
        for(unsigned int i = 0; i < armament.size(); i += 1) {
            sum += armament.at(i).weaponInt;
        }
        return sum;
    }

    // Adds an existing weapon to a ship
    void addWeapon(Weapon wep) {
        armament.push_back(wep);
    }


    // Adds a new weapon to a ship and returns the pointer to that weapon
    Weapon* addWeapon(string nameIn, int intIn, float floatIn) {
        Weapon* hold = new Weapon(nameIn, intIn, floatIn);
        armament.push_back(*hold);
        return hold;
    }


    // Prints ship information
	void printEntry() {
        cout << "Name: " << name << endl;
        cout << "Class: " << shipClass << endl;
        cout << "Length: " << length << endl;
        cout << "Shield capacity: " << shield << endl;
        cout << "Maximum Warp: " << warpSpeed << endl;
        cout << "Armaments:" << endl;
        if (armament.size() == 0) {
            cout << "Unarmed" <<endl;
        }
        else {
            for(unsigned int i = 0; i < armament.size(); i += 1) {
                armament.at(i).printWeapon();
            }
            cout << "Total firepower: " << calculateFirepower() << endl;
        }
        cout << endl;
	}
};

void readBinaryFile(string* file, vector<Ship>* holding) {

    // ========= Function Setup =========
    // Creates a reader
    ifstream reader;
    reader.open(*file,ios_base::binary);

    // Gets the length of the file
    int amount;
    reader.read((char*)&amount, 4);

    // Creates a temporary buffer and translating variables
    char* buffer;
    cout <<"Amount: "<< amount << endl;
    for (int i = 0; i < amount; i += 1) {

        // ========= Ship Name =========

        //Gets the length of the string
        int len;
        reader.read((char*)&len, 4);
        buffer = new char[len];

        // Reads the name of the ship
        reader.clear();
        reader.read(buffer, len);

        // Creates a string out of the char array and deletes array
        string shipName = buffer;
        delete[] buffer;





        // ========= Ship Class =========

        // Gets the length of the string
        reader.read((char*)&len, 4);

        buffer = new char[len];

        // Reads the string and creates and string out of the char array
        reader.read(buffer, len);
        string shipClass = buffer;
        delete[] buffer;





        // ========= Ship Length =========
        short shipLength;
        reader.read((char*)&shipLength, 2);
        reader.clear();
        




        // ========= Ship Shield =========
        int shipShield;
        reader.read((char*)&shipShield, 4);
        reader.clear();





        // ========= Ship Warp Speed =========
        float shipWarp;
        reader.read((char*)&shipWarp, 4);

        Ship* holdingptr;
        holdingptr = new Ship(shipName, shipClass, shipLength, shipShield, shipWarp);
        holding->push_back(*holdingptr);
        delete holdingptr;





        // ========= Ship Weapons Setup =========
        unsigned int wepAmount;
        reader.read((char*)&wepAmount, 4); // Wepamount incorrect
        reader.clear();

        string wepName;
        int wepPower;
        float wepConsumption;

        Weapon* wepHold;



        //cout << "Weapon Loop" << endl;
        //cout << wepAmount << endl;
        // ========= Ship Weapons Loop =========
        for (unsigned int j = 0; j < 3; j += 1) {
            reader.read((char*)&len, 4);
            buffer = new char[len];
            reader.clear();
            reader.read(buffer, len);
            wepName = buffer;
            delete[] buffer;
            reader.read((char*)&wepPower, 4);
            reader.read((char*)&wepConsumption,4);
            wepHold = new Weapon(wepName, wepPower, wepConsumption);
            holding->at(i).armament.push_back(*wepHold);
            delete wepHold;
            reader.clear();
            //cout << "Weapon Loop End" << endl;
        }
    }
}

int mainFunction()
{   
    // Creates holding array for easy file access
    //string files[2] = {"C:\\Users\\Leonardo\\Documents\\School Stuff\\Classwork\\Sophmore Year\\Spring 22\\COP3503\\Code\\COP3503\\Lab_5\\friendlyships.shp","C:\\Users\\Leonardo\\Documents\\School Stuff\\Classwork\\Sophmore Year\\Spring 22\\COP3503\\Code\\COP3503\\Lab_5\\enemyships.shp"};

    // Creates holding array for easy file access (Zybooks)
    string files[2] = {"friendlyships.shp","enermyships.shp"};

    // Creates holding vector for ships
    vector<Ship> ships;

    // First menu options
    /*
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
    */
	int option;

    // Test Determining Variables
    option = 1;
	//cin >> option;

   /* Load files here */
   if (option > 3 || option < 1) {
       cout << "Invalid Input. Your input: " << option << endl;
   }
   else if (option == 1) {
       readBinaryFile(&files[0], &ships);
   }
   else if (option == 2) {
       readBinaryFile(&(files[1]), &ships);
   }
   else {
       readBinaryFile(&files[0], &ships);
       readBinaryFile(&files[1], &ships);
   }
   

    // Second Menu options
    /*
	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;
    */
	
    // Second setting of Test Determining Variables
    option = 1;
    cout << option << endl;
	//cin >> option;
	
    // Checks input is valid
    if (option > 5 || option < 1) {
        cout << "Invalid Input. Your input: " << option << endl;
    }
	
    // Print all ships
    else if(option == 1) {

        // Loops through ship holding vector printing ships
        for(unsigned int i = 0; i < ships.size(); i += 1) {
            ships.at(i).printEntry();
        }
    }

    // Print strongest weapon ship
    else if(option == 2) {
        int index;
        int comp = 0;
        for(unsigned int i = 0; i < ships.size(); i += 1) {
            for (unsigned int j = 0; j < ships.at(i).armament.size(); j += 1) {
                if(ships.at(i).armament.at(j).weaponInt > comp) {
                    comp = ships.at(i).armament.at(j).weaponInt;
                    index = i;
                }
            }
        }
        ships.at(index).printEntry();
    }



    // Print strongest overall ship
    else if(option == 3) {
        int comp = 0;

        for(unsigned int i = 0; i < ships.size(); i += 1) {
            if(ships.at(i).calculateFirepower() > ships.at(comp).calculateFirepower()) {
                comp = i;
            }
        }
        ships.at(comp).printEntry();
    }

    // Print weakest ship (ignoring unarmed) Answer should be 250
    else if(option == 4) {
        int comp = 0;

        for(unsigned int i = 0; i < ships.size(); i += 1) {
            if (ships.at(i).calculateFirepower() != 0) {
                if(ships.at(comp).calculateFirepower() > ships.at(i).calculateFirepower()) {
                    comp = i;
                }
            }
        }

        ships.at(comp).printEntry();
    }

    // Prints unarmed ships
    else if(option == 5) {

        for(unsigned int i = 0; i < ships.size(); i += 1) {
            if (ships.at(i).calculateFirepower() == 0) {
                ships.at(i).printEntry();
            }
        }
    }
	
   return 0;
}

int main() {
	mainFunction();

    return 0;
}