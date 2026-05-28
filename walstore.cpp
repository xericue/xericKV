#include "walstore.h"
#include "walentry.h"
#include <string>

// constructor
WALStore::WALStore(std::string data_file, std::string wal_file)
    : data_file {data_file}
    , wal_file {wal_file}
{
}

// void recover() {
//     std::cout << "hi\n"
// }

// ngl i still have no mental schema here

// is WALStore:: how i make it a method of the class!?
void WALStore::set(std::string key, std::string value) {
    // Enter a new KV pair with WAL using 'set'
    WALEntry entry("set", key, NULL); // NULL check this later
    // _append_wal
    // learn how to set data[key] = value in an unordered map
    // now how do i get to my unordered map. do i use a pointer to go
    // directly to it?
}

void WALStore::del(std::string key) {
    // Delete a key, log it in your WAL.
    WALEntry entry("del", key, NULL);
    // _append_wal(entry);
    // data.erase(key);
}

void checkpoint() {
    
}