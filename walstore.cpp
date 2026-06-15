#include "walstore.h"
#include "walentry.h"
#include <string>


void WALStore::m_append_wal(WALEntry walentry) {
    std::cout << "dummy\n";
}

void WALStore::m_recover() {
    std::cout << "dummy\n";
}

// constructor
WALStore::WALStore(std::string data_file, std::string wal_file)
    : data_file {data_file} // what the heck is std::move
    , wal_file {wal_file}

    // ^ why the hell does std::move on a string
    // avoid copying the underlying character buffer

    // data is implicitly default-constructed?
    // oh because member variables w/ default constructors
    // are automatically constructor before constructor
    // body runs
{
    m_recover(); // call disk loading
}

// is WALStore:: how i make it a method of the class!?
void WALStore::set(std::string key, std::string value) {
    // Enter a new KV pair with WAL using 'set'
    WALEntry entry("set", key, NULL); // NULL check this later
    // _append_wal
    // learn how to set data[key] = value in an unordered map
    // now how do i get to my unordered map. do i use a pointer to go
    // directly to it?
}

// ohhh, its becaeuse it doesnt need to OWN the string; it
// just needs to read it - pass a const reference

// need to store it: take by value, std::move
// need to look: const std::string&

// avoids unnecessary copies - no 1000 byte string moving
// around; simply 8 bytes (a pointer) as std::string is
// heap allocated buffer

void WALStore::del(const std::string& key) { // why std::string&
    // Delete a key, log it in your WAL.
    WALEntry entry("del", key, NULL);
    // _append_wal(entry);
    // data.erase(key);
}

void WALStore::checkpoint() {
    std::cout << "dummy\n";
}