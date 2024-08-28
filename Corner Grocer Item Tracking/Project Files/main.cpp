// Ryan Orton
// CS210
// Project 3
// 8-15-24


#include <iostream> // Include standard input/output stream library
#include <limits>   // Include limits library for numeric limits
#include "ItemTracker.h" // Include custom header for ItemTracker class
#include "FileManager.h" // Include custom header for FileManager class

int main() {
    // Create instances of ItemTracker and FileManager
    ItemTracker tracker;
    FileManager fileManager;

    // Load item data from a file into the ItemTracker instance
    tracker.loadItemsFromFile("CS210_Project_Three_Input_File.txt");

    // Create a backup file with item frequencies using FileManager
    fileManager.createBackupFile("frequency.dat", tracker.getAllFrequencies());

    int option; // Variable to store user menu choice

    // Loop until the user chooses to exit
    do {
        // Display the menu options to the user
        std::cout << "Menu:\n";
        std::cout << "1. Search for item frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print item frequency histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter option: ";
        std::cin >> option; // Get user input for menu option

        // Process user input and perform the corresponding action
        switch (option) {
        case 1: {
            std::string item; // Variable to store the item to search for
            std::cout << "Enter item to search: ";
            std::cin >> item; // Get user input for the item
            // Output the frequency of the specified item
            std::cout << item << " appears " << tracker.getItemFrequency(item) << " times.\n";
            break; // Exit the case block
        }
        case 2:
            // Print all item frequencies
            tracker.printAllFrequencies();
            break; // Exit the case block
        case 3:
            // Print the item frequency histogram
            tracker.printHistogram();
            break; // Exit the case block
        case 4:
            // Print exit message and terminate the loop
            std::cout << "Exiting...\n";
            break; // Exit the case block
        default:
            // Handle invalid menu option
            std::cout << "Invalid option. Please try again.\n";
            break; // Exit the case block
        }
    } while (option != 4); // Continue looping until the user chooses to exit

    return 0; // Indicate that the program ended successfully
}
