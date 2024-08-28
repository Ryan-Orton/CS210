#ifndef ITEMTRACKER_H // Include guard to prevent multiple inclusions
#define ITEMTRACKER_H

#include <map>       // Include map container library for key-value pairs
#include <string>    // Include string library for string manipulation

// Class definition for ItemTracker
class ItemTracker {
private:
    // Map to store item names and their corresponding frequencies
    std::map<std::string, int> itemFrequency;

public:
    // Method to load items from a file and populate the itemFrequency map
    void loadItemsFromFile(const std::string& filename);

    // Method to get the frequency of a specific item
    int getItemFrequency(const std::string& item);

    // Method to print all item frequencies
    void printAllFrequencies();

    // Method to print a histogram of item frequencies
    void printHistogram();

    // Method to retrieve all item frequencies as a map
    std::map<std::string, int> getAllFrequencies();  // Added this method to retrieve all frequencies
};

#endif // ITEMTRACKER_H // End of include guard


