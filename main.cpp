#include <iostream>
#include <vector>
#include "walentry.h" // why the header file and not cpp?
// this is saying insert contents of walentry.h here
#include "walstore.h"
#include "lsmtree.h"


int main() {
    // instantiate a new object LSMTree with a base file path
    LSMTree database {"bruh"};
    
    std::cout << "XerickKV :D\n";
    std::cout << "commands: set <key> <value>     get <key>     del <key>     range <start:001> <end:xxx>     exit\n\n";
    // std::cout << "\nexample of range:\ndb> set item:001 bruh\ndb> set item:002 bruhh\ndb> range item:001 item:002\nitem:001:    bruh\nitem:002:    bruhh\n\n";
    
    // from now on will need to compile all relevant code
    // files on compile line, such as
    // g++ main.cpp walentry.cpp walstore.cpp -o main

    // GURTTT

    while (true) {
        std::string line;

        std::cout << "db>";
        std::cin >> line;
        std::cout << database.get(line) << "\n";

    }
    
    return 0;
}