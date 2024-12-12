#pragma once
#include <map>
#include <string>
using namespace std;

class ItemTracker {
private:
	map<string, int> groceryPopulation;
	string groceryName;
	
public:
	ItemTracker();

	// Display Menu for less repetition, cleaner display
	void displayMenu();
	// Reads the file and updates the map with item frequencies.
	void loadInput();

	//Loops through the map and writes the frequencies to the frequency.dat file.
	void saveData();

	//Allows the users to search for a specific item's frequency
	void searchPurchases(const string& groceryName);

	// Displays all items and their frequency in a list
	void listPurchases();

	// Displays all items and their frequency in a histogram
	void listHistogram();


};

