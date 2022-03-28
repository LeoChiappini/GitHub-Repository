#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Entry {
	// Number,Theme,Name,Minifigs,Pieces,USPrice
	int number;
	string theme;
	string name;
	int minifigs;
	int pieces;
	double price;

	Entry(int numberIn, string themeIn, string nameIn, int minifigsIn, int piecesIn, double priceIn) {
		number = numberIn;
		theme = themeIn;
		name = nameIn;
		minifigs = minifigsIn;
		pieces = piecesIn;
		price = priceIn;
	}

	void printEntry() {

		cout << "Name: " << name << endl;
		cout << "Number: " << number << endl;
		cout << "Theme: " << theme << endl;
		cout << "Price: $" << price << endl;
		cout << "Minifigures: " << minifigs << endl;
		cout << "Piece count: " << pieces << endl;
	}

};

int mainFunction()
{
	cout << std::fixed << std::setprecision(2);

	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

   /*======= Load data from file(s) =======*/

   // Create an array to hold the files for easy access
	string files[3] = {"C:\\Users\\Leonardo\\Documents\\School Stuff\\Classwork\\Sophmore Year\\Spring 22\\COP3503\\Code\\COP3503\\Lab_4\\lego1.csv", "C:\\Users\\Leonardo\\Documents\\School Stuff\\Classwork\\Sophmore Year\\Spring 22\\COP3503\\Code\\COP3503\\Lab_4\\lego2.csv", "C:\\Users\\Leonardo\\Documents\\School Stuff\\Classwork\\Sophmore Year\\Spring 22\\COP3503\\Code\\COP3503\\Lab_4\\lego3.csv"};
	
	// Creates an array for Zybooks use
	//string files[3] = {"lego1.csv","lego2.csv","lego3.csv"};

	// Create a stream
	ifstream inFS;
	string data;
	vector<Entry> list;

	// Determines which file to load and opens it
	if (option < 1 || option > 4) {
		cout << "Invalid Input. Your input was: " << to_string(option) << endl;
	}
	else if (option == 4) {
		//inFS.open(files[1]);
		//inFS.open(files[2]);
		//inFS.open(files[3]);
	}
	else {
		inFS.open(files[option-1]);
	}

	// Determines if file is open
	if(option == 4) {

	}
	else if (!inFS.is_open()) {
		cout << "Could not open the file: " << files[option-1] << endl;
	}

	// Gets the header of the file to avoid an extra entry
	getline(inFS, data);

	// Reads the data, organizes it, and creates an Entry

	// Declares holding variables for Entry creation
	int numberIn;
	string themeIn;
	string nameIn;
	int minifigsIn;
	int piecesIn;
	double priceIn;
	int index;

	// Reads entire file and creates entries - Done
	if (option == 4) {
		for (int i = 0; i < 3; i += 1) {
			inFS.open(files[i]);
			getline(inFS, data); // Gets the headers to avoid extra entry
			while(!inFS.fail()) {

			// Checks to see if file end has been reached
			if (inFS.eof()) {
				break;
			}
			
			getline(inFS, data);

			// Reads Number
			index = data.find(",");
			numberIn = stoi(data.substr(0, index));
			data = data.substr(index+1);


			// Reads Theme
			index = data.find(",");
			themeIn = data.substr(0, index);
			data = data.substr(index+1);


			// Reads Name
			index = data.find(",");
			nameIn = data.substr(0, index);
			data = data.substr(index+1);


			// Reads Minifigs
			index = data.find(",");
			minifigsIn = stoi(data.substr(0,index));
			data = data.substr(index+1);


			// Reads Pieces
			index = data.find(",");
			piecesIn = stoi(data.substr(0,index));
			data = data.substr(index+1);


			// Reads Price
			index = data.find(",");
			priceIn = (stod(data.substr(0,index)));
			data = data.substr(index+1);


			// Creates an entry and puts it in the list vector
			list.push_back(Entry(numberIn, themeIn, nameIn, minifigsIn, piecesIn, priceIn));
			}
			inFS.close();
		}
	}
	else {
		while(!inFS.fail()) {

			// Checks to see if file end has been reached
			if (inFS.eof()) {
				break;
			}

			getline(inFS, data);

			// Reads Number
			index = data.find(",");
			numberIn = stoi(data.substr(0, index));
			data = data.substr(index+1);

			// Reads Theme
			index = data.find(",");
			themeIn = data.substr(0, index);
			data = data.substr(index+1);

			// Reads Name
			index = data.find(",");
			nameIn = data.substr(0, index);
			data = data.substr(index+1);

			// Reads Minifigs
			index = data.find(",");
			minifigsIn = stoi(data.substr(0,index));
			data = data.substr(index+1);

			// Reads Pieces
			index = data.find(",");
			piecesIn = stoi(data.substr(0,index));
			data = data.substr(index+1);

			// Reads Price
			index = data.find(",");
			priceIn = (stod(data.substr(0,index)));
			data = data.substr(index+1);

			// Creates an entry and puts it in the list vector
			list.push_back(Entry(numberIn, themeIn, nameIn, minifigsIn, piecesIn, priceIn));
		}
	}

	// Menu Options for 2nd Menu
	
	
	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;
   
	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << to_string(list.size()) << endl << endl;


	/*======= Based on the choice, execute the appropriate task and show the results =======*/

	// Most Expensive Set - Done
	if (choice == 1) {
		int comp = 0;
		for(long unsigned int i = 0; i < list.size(); i += 1) {
			if(list.at(i).price > list.at(comp).price)
				comp = i;
		}
		cout << "The most expensive set is: " << endl;
		list.at(comp).printEntry();
	}
	// Largest Piece Count - Done
	else if (choice == 2) {
		int comp = 0;
		for(long unsigned int i = 0; i < list.size(); i += 1) {
			if(list.at(i).pieces > list.at(comp).pieces)
				comp = i;
		}
		cout << "The set with the highest parts count:" << endl << endl;
		list.at(comp).printEntry();
	}
	// Set Name Containing - PROBLEM
	else if (choice == 3) {

		// Gets input from user as a search term
		bool found = false;
		string comp;
		vector<int> hold;
		//cout << "Enter name of set" << endl;
		getline(cin, comp);
		cin.get(); // Clear input for future input

		for(long unsigned int i = 0; i < list.size(); i += 1) {
			if (list.at(i).name.find(comp) != string::npos) {
				hold.push_back(i);
				found = true;
			}
		}
		if (found == false) {
			cout << "No sets found matching that search term" << endl;
		}
		else {
			cout << "Sets matching \""<< comp << "\":" << endl << endl;
			for(long unsigned int i = 0; i < hold.size(); i += 1) {
				cout << to_string(list.at(hold.at(i)).number) << " " << list.at(hold.at(i)).name << " $" << list.at(hold.at(i)).price << endl;
			}
		}
	}
	// Theme Search - Done
	else if (choice == 4) {
		// Gets input from user as a search term
		bool found = false;
		string comp;
		vector<int> hold;
		//cout << "Enter theme of set" << endl;
		getline(cin, comp);
		cin.get(); // Clear input for future input

		

		for(long unsigned int i = 0; i < list.size(); i += 1) {
			if (list.at(i).theme.find(comp) != string::npos) {
				hold.push_back(i);
				found = true;
			}
		}
		if (found == false) {
			cout << "No sets found matching that search term" << endl;
		}
		else {
			cout << "Sets matching \""<< comp << "\":" << endl << endl;
			for(long unsigned int i = 0; i < hold.size(); i += 1) {
				cout << to_string(list.at(hold.at(i)).number) << " " << list.at(hold.at(i)).name << " $" << list.at(hold.at(i)).price << endl;
			}
		}
	}
	// Part Count Information - Done
	else if (choice == 5) {
		int pieceSum = 0;
		for(long unsigned int i = 0; i < list.size(); i += 1) {
			pieceSum += list.at(i).pieces;
		}
		cout << std::fixed << std::setprecision(2);
		cout << "Average part count for " << to_string(list.size()) << " sets: " << to_string(pieceSum/list.size()) << endl;
	}
	// Price Information - Problem
	else if (choice == 6) {
		int minPrice = 0;
		int maxPrice = 0;
		double sumPrice = 0;
		for(long unsigned int i = 0; i < list.size(); i += 1) {
			sumPrice += list.at(i).price;
			cout << sumPrice << endl;
			if(list.at(i).price > list.at(maxPrice).price) {
				maxPrice = i;
			}
			else if(list.at(i).price < list.at(minPrice).price) {
				minPrice = i;
			}
		}
		double disp = sumPrice / ((double)(list.size()));
		cout << "Average price for " << to_string(list.size()) << " sets: $" << disp << endl; 
		cout << endl;
		cout << "Least expensive set:" << endl;
		list.at(minPrice).printEntry();
		cout << endl;
		cout << "Most expensive set:" << endl;
		list.at(maxPrice).printEntry();
	}
	// Minifigure Information - Untested
	else if (choice == 7) {
		int minifigSum = 0;
		int minifigMax = 0;
		for(long unsigned int i = 0; i < list.size(); i += 1) {
			minifigSum += list.at(i).minifigs;
			if(list.at(i).minifigs > list.at(minifigMax).minifigs) {
				minifigMax = i;
			}
		}
		cout << "Average number of minifigures: " << to_string(minifigSum/list.size()) << endl;
		cout << "Set with the most minifigures: " << endl;
		list.at(minifigMax).printEntry();
	}
	// If you bought one of everything
	else if (choice == 8) {
		double sumPrice = 0;
		int sumPieces = 0;
		int sumMinifig = 0;
		for(long unsigned int i = 0; i < list.size(); i += 1) {
			sumPrice += list.at(i).price;
			sumPieces += list.at(i).pieces;
			sumMinifig += list.at(i).minifigs;
		}
		cout << "If you bought one of everything..." << endl;
		cout << "It would cost: $" << sumPrice << endl;
		cout << "You would have " << to_string(sumPieces) << " pieces in your collection" << endl;
		cout << "You would have an army of " << to_string(sumMinifig) << " minifigures!" << endl;

	}
	// Quit
	else if (choice == 0) {
		return 0;
	}
	else {
		cout << "Invalid Input" << endl;
	}


	return 0;
}

int main() {
	mainFunction();
}

