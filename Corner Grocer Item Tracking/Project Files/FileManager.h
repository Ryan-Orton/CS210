#ifndef FILEMANAGER_H // Include guard to prevent multiple inclusions
#define FILEMANAGER_H

#include <map>       // Include map container library for key-value pairs
#include <string>    // Include string library for string manipulation

// Class definition for FileManager
class FileManager {
public:
    // Method to create a backup file containing item frequencies
    void createBackupFile(const std::string& filename, const std::map<std::string, int>& items);
};

#endif // FILEMANAGER_H // End of include guard

