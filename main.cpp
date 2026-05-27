#include <iostream>
#include "walentry.h" // why the header file and not cpp?
// this is saying insert contents of walentry.h here

int main() {
    /*
    std::cout << "yo welcome to the write-heavy database bruh. you got a few commands:\n";
    std::cout << "set <key> <value>\nget <key>\ndel <key>\nrange <start> <end>\nexit\n";
    std::cout << "\nexample of range:\ndb> set item:001 bruh\ndb> set item:002 bruhh\ndb> range item:001 item:002\nitem:001:    bruh\nitem:002:    bruhh\n";
    */

    // GURTTT
    [[maybe_unused]] WALEntry bruh {67};
    std::cout << bruh.gurt << "\n"; // its not +; its << in C++

    return 0;
}