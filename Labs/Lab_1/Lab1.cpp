#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    // Initilizes varibles for holding the names
    string chartTitle;
    string colOneName;
    string colTwoName;
    // string chartTitle = "Number of Novels Authored";
    // string colOneName = "Author name";
    // string colTwoName = "Number of novels";

    // Assigns values to aforementioned variables
    cout << "Enter a title for the data:" << endl;
    getline(cin, chartTitle);
    cout << "You entered: " + chartTitle << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, colOneName);
    cout << "You entered: " + colOneName << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, colTwoName);
    cout << "You entered: " + colTwoName << endl;
    

    // Creates while loop variable, holding variable, and vectors
    bool keepGoing = true;
    string holding;
    vector<string> names;
    vector<int> numbers;
    // vector<string> names = {"Jane Austen", "Charles Dickens", "Ernest Hemingway", "Jack Kerouac", "F. Scott Fitzgerald", "Mary Shelley", "Charlotte Bronte", "Mark Twain", "Agatha Christie", "Ian Flemming", "J.K. Rowling", "Stephen King", "Oscar Wilde"};
    // vector<int> numbers = {6,20,9,22,8,7,5,11,73,14,14,54,1};

    // Currently works assuming correct format
    while (holding.compare("-1") != 0)
    {
       cout << "Enter a data point (-1 to stop input):" << endl;
       getline(cin, holding);
       try {
           if (holding == to_string(-1)) {
                keepGoing = false;
                break;
           }
           else if (holding.find(",") > holding.length()) {
               cout << "Error: No comma in string." <<endl;
           }
           else {
               string splitString = holding.substr(holding.find(",")+2);
               if (splitString.find(",") != -1) { cout << "Error: Too many commas in input." << endl;}
               else {
                   int num = stoi(splitString);
                   string word = holding.substr(0, holding.find(","));
                   cout << "Data string: " << word << endl;
                   cout << "Data integer: " << num << endl;
                   names.push_back(word);
                   numbers.push_back(num);
               }
           }
       }
       catch (invalid_argument) {
           cout << "Error: Comma not followed by an integer." << endl;
       }
    }
    // Table Maker
    // Table Header
    cout << endl;
    cout << right << setw(33) << chartTitle << endl;
    cout << left << setw(20) << colOneName << "|" << right << setw(23) << colTwoName << endl;
    for(int c = 0; c < 44; c+= 1) { cout << "-"; }
    cout << endl;
    // Table Contents
    for (int c = 0; c < names.size();c += 1){
        cout << left << setw(20) << names[c] << "|" << right << setw(23) << numbers[c] << endl;
    }
    // Histogram Maker
    for (int c = 0; c < names.size(); c+= 1){
        cout << endl << right << setw(20) << names[c] << " ";
        for (int secondc = 0; secondc < numbers[c]; secondc += 1){
            cout << "*";
        }
    }
    cout << endl;

    return 0;
}