#include <iostream>
#include <string>
// declarations of methods/classes go here

class WALEntry {
    private:
        std::string timestamp;
        std::string operation;
        std::string key;
        std::string value;
    
    public:
        // because you have to initialize the constructor itself lol
        WALEntry(std::string operation, std::string key, std::string value);

        // other methods here (all methods are mostly public whereas data is private -
        // proper OOP encapsulation

    
};