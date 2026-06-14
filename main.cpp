#include <iostream>
#include <vector>
#include "walentry.h" // why the header file and not cpp?
// this is saying insert contents of walentry.h here
#include "walstore.h"

class LSMTree {
private:
    std::string m_base_path;
    std::vector<int> m_memtable, m_sstables;
    int m_max_sstables {5};
    // need to instantiate a thread lock
    // need to instantiate a WAL

    void m_load_sstables() {
        std::cout << "dummy\n";
    }

    void m_flush_memtable() {
        std::cout << "dummy\n";
    }

    void m_compact() {
        std::cout << "dummy\n";
    }


public:
    LSMTree(std::string base_path) {
        // how do i construct a path Lol Lol Lol
        m_base_path = base_path; // python does this iwth Path()?

    }

    void set(std::string key, std::string value) {
        std::cout << "dummy\n";
    }

    std::string get(std::string key) {
        return "dummy";
    }

    void del(std::string key) {
        // using a lock, add a "delete" log to the WAL
        // add a tombstone to the memtable
        std::cout << "dummy\n";
    }

    void range_query(std::string start_key, std::string end_key) {
        std::cout << "dummy\n";
    }
    
    void close() {
        std::cout << "dummy\n";

        // checkpoint on wal - ensure its up to date
    }
};


int main() {

    // instantiate a new object LSMTree with a base file path
    LSMTree database {"bruh"};
    
    std::cout << "XerickKV :D\n";
    std::cout << "commands: set <key> <value>     get <key>     del <key>     range <start:001> <end:xxx>     exit\n";
    std::cout << "\nexample of range:\ndb> set item:001 bruh\ndb> set item:002 bruhh\ndb> range item:001 item:002\nitem:001:    bruh\nitem:002:    bruhh\n";
    
    // from now on will need to compile all relevant code
    // files on compile line, such as
    // g++ main.cpp walentry.cpp walstore.cpp -o main

    // GURTTT
    std::cout << "Hi" << "\n"; // its not +; its << in C++

    return 0;
}