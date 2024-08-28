#include <iostream>  // Include standard input/output stream library
#include "FileManager.h" // Include the header file for the FileManager class
#include <fstream>   // Include file stream library for file operations
#include <map>       // Include map container library for key-value pairs
#include <string>    // Include string library for string manipulation

// Implementation of the createBackupFile method
void FileManager::createBackupFile(const std::string& filename, const std::map<std::string, int>& items) {
    // Open the output file with the given filename
    std::ofstream outputFile(filename);

    // Check if the file was successfully opened
    if (outputFile.is_open()) {
        // Iterate over each entry in the items map
        for (const auto& entry : items) {
            // Write the item and its frequency to the file
            outputFile << entry.first << " " << entry.second << std::endl;
        }
        // Close the output file after writing
        outputFile.close();
    }
    else {
        // Print an error message if the file could not be created
        std::cerr << "Unable to create file " << filename << std::endl;
    }
}

