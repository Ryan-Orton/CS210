#include "ItemTracker.h" // Include the header file for the ItemTracker class
#include <fstream>       // Include file stream library for file operations
#include <iostream>      // Include standard input/output stream library

// Method to load items from a file and populate the itemFrequency map
void ItemTracker::loadItemsFromFile(const std::string& filename) {
    // Open the input file with the given filename
    std::ifstream inputFile(filename);

    // Variable to hold each item read from the file
    std::string item;

    // Read items from the file and update their frequencies in the map
    while (inputFile >> item) {
        itemFrequency[item]++; // Increment the count for the current item
    }
}

// Method to get the frequency of a specific item
int ItemTracker::getItemFrequency(const std::string& item) {
    // Check if the item exists in the itemFrequency map
    if (itemFrequency.find(item) != itemFrequency.end()) {
        // Return the frequency of the item
        return itemFrequency[item];
    }
    else {
        // If the item is not found, return 0
        return 0;
    }
}

// Method to print all item frequencies
void ItemTracker::printAllFrequencies() {
    // Iterate over each entry in the itemFrequency map
    for (const auto& entry : itemFrequency) {
        // Print the item and its frequency
        std::cout << entry.first << " " << entry.second << std::endl;
    }
}

// Method to print a histogram of item frequencies
void ItemTracker::printHistogram() {
    for (const auto& entry : itemFrequency) {
        std::cout << entry.first << " ";
        for (int i = 0; i < entry.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// Method to return the entire itemFrequency map
std::map<std::string, int> ItemTracker::getAllFrequencies() {
    return itemFrequency;
}

