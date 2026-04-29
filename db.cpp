#include <iostream>

int main() {
    std::cout << "yo welcome to the write-heavy database bruh. you got a few commands:\n";
    std::cout << "set <key> <value>\nget <key>\ndel <key>\nrange <start> <end>\nexit\n";
    std::cout << "\nexample of range:\ndb> set item:001 bruh\ndb> set item:002 bruhh\ndb> range item:001 item:002\nitem:001:    bruh\nitem:002:    bruhh\n";
    return 0;
}