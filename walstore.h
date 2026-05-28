#ifndef WALSTORE_H
#define WALSTORE_H

#include <iostream>
#include <string>
#include <unordered_map>

class WALStore {
    private:
        std::string data_file;
        std::string wal_file;
        std::unordered_map<std::string, std::string> data;
        // call recover here?

    public:
        WALStore(std::string data_file, std::string wal_file);
        void set(std::string key, std::string value);
        void del(std::string key);
        void checkpoint();


};

#endif