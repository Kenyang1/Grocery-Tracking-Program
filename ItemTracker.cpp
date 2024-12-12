#include "ItemTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor for the ItemTracker class
ItemTracker::ItemTracker() {
    groceryName = groceryName; 
}

// Function to display the main menu to the user
void ItemTracker::displayMenu() {
    cout << "Enter options" << endl;
    cout << "1. Input word for search" << endl;
    cout << "2. Print List of purchases" << endl;
    cout << "3. Print Purchases in form of histogram" << endl;
    cout << "4. Exit Program" << endl;
}

// Function to load input data from a file and populate the groceryPopulation map
void ItemTracker::loadInput() {
    groceryPopulation.clear(); // Clear existing data to avoid duplication

    ifstream myFile; // Input file stream
    myFile.open("CS210_Project_Three_Input_File.txt", ios::in);
    if (!myFile.is_open()) {
        // If the file fails to open, display an error message
        cout << "File 'CS210_Project_Three_Input_File.txt' cannot be opened. ";
        cout << "Please check if the file exists." << endl;
        return;
    }

    // Read each word from the file and update the frequency map
    while (myFile >> groceryName) {
        if (groceryPopulation.find(groceryName) != groceryPopulation.end()) {
            // If the item exists in the map, increment its frequency
            groceryPopulation[groceryName]++;
        }
        else {
            // If the item does not exist, add it to the map with a frequency of 1
            groceryPopulation[groceryName] = 1;
        }
    }
    myFile.close(); // Close the file after reading
    cout << "Data loaded successfully." << endl;
}

// Function to save grocery data to a file
void ItemTracker::saveData() {
    if (groceryPopulation.empty()) {
        // If no data exists in the map, inform the user and return
        cout << "No data to save." << endl;
        return;
    }

    ofstream outFile; // Output file stream
    outFile.open("frequency.dat.txt", ios::out);
    if (!outFile.is_open()) {
        // If the file fails to open, display an error message
        cout << "File 'frequency.dat.txt' cannot be opened. ";
        cout << "Please check if the file exists." << endl;
        return;
    }

    // Write each item and its frequency to the file
    for (const auto& pair : groceryPopulation) {
        outFile << pair.first << " : " << pair.second << endl;
    }

    cout << "Data saved successfully." << endl;
    outFile.close(); // Close the file after writing
}

// Function to search for a specific item's purchase frequency
void ItemTracker::searchPurchases(const string& groceryName) {
    if (groceryPopulation.find(groceryName) != groceryPopulation.end()) {
        // If the item exists in the map, print its frequency
        cout << groceryName << " " << groceryPopulation[groceryName] << endl;
    }
    else {
        // If the item is not found, inform the user
        cout << "Item " << groceryName << " is not found in the purchase list." << endl;
    }
}

// Function to list all items and their purchase frequencies
void ItemTracker::listPurchases() {
    if (groceryPopulation.empty()) {
        // If no data exists in the map, inform the user
        cout << "No data to display." << endl;
        return;
    }

    // Print each item and its frequency
    for (const auto& pair : groceryPopulation) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Function to display a histogram of purchase frequencies
void ItemTracker::listHistogram() {
    if (groceryPopulation.empty()) {
        // If no data exists in the map, inform the user
        cout << "No data to display." << endl;
        return;
    }

    // Print each item followed by asterisks representing its frequency
    for (const auto& pair : groceryPopulation) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}
