/*
 * Developer: Kenyang Lual
 * Date: December 12, 2024
 * Purpose:  This header file defines the `ItemTracker` class, which provides functionality 
 *          to track grocery item frequencies from a text file. It supports searching 
 *          for specific items, displaying item frequencies, generating a histogram, 
 *          and saving data to a backup file.
 */

#include <iostream>
#include "ItemTracker.h"
#include <cctype> 
using namespace std;

int main() {
    int choice; // User's menu choice
    string item; // Item name for search functionality

    // Create an instance of the ItemTracker class
    ItemTracker itemTracker;

    // Load data from the input file and save it to the frequency data file
    itemTracker.loadInput();
    itemTracker.saveData();

    // Main program loop
    do {
        itemTracker.displayMenu();

        // Input validation: Ensure the user enters a valid number
        while (!(cin >> choice) || (choice <= 0 || choice > 4)) {
            cout << "Invalid input. Please enter a valid number (1-4)." << endl;
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << endl;
            itemTracker.displayMenu(); // Redisplay the menu
        }

        // Perform actions based on the user's menu choice
        switch (choice) {
        case 1: // Search purchases
            cout << "Searching purchases..." << endl;
            cout << "Enter item to look up: ";
            cin >> item;

            // Adjust the casing of the input to standardize the format (capitalize the first letter)
            if (!item.empty()) {
                item[0] = toupper(item[0]); // Capitalize the first character
                for (size_t i = 1; i < item.size(); ++i) {
                    item[i] = tolower(item[i]); // Convert the remaining characters to lowercase
                }
            }

            // Search for the item in the tracker
            itemTracker.searchPurchases(item);
            cout << endl;
            break;

        case 2: // Print list of purchases
            cout << "Printing List..." << endl;
            itemTracker.listPurchases(); // List all items with their frequencies
            cout << endl;
            break;

        case 3: // Print histogram
            cout << "Printing Histogram..." << endl;
            itemTracker.listHistogram(); // Display a histogram of item frequencies
            cout << endl;
            break;

        case 4: // Exit program
            cout << "Exiting Program..." << endl;
            break;

        default: // Handle invalid menu options (should not occur with valid input)
            cout << "Invalid Option" << endl;
            break;
        }

    } while (choice != 4); // Exit loop when the user selects option 4

    return 0; 
}
