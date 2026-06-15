#ifndef WALSTORE_H
#define WALSTORE_H

#include <iostream>
#include <string>
#include <unordered_map>

class WALStore {
    public:
        WALStore(std::string data_file, std::string wal_file);
        void set(std::string key, std::string value);
        void del(std::string key);
        void checkpoint();

    private:
        std::string data_file;
        std::string wal_file;
        std::unordered_map<std::string, std::string> data;
        // call recover here?
        void m_append_wal(WALEntry walentry);
        void m_recover();
};

#endif