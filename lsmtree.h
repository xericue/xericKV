#ifndef LSMTREE_H
#define LSMTREE_H
#include <string>
#include <vector>
#include <iostream>

// basically if lsmtree header file wasnt defined run
// the following (the entire header file) - preprocessing
// directives

// class definitions and function declarations go 
// in header files

class LSMTree {
private:
    std::string m_base_path;
    std::vector<int> m_memtable, m_sstables;
    int m_max_sstables {5};
    // need to instantiate a thread lock
    // need to instantiate a WAL

    void m_load_sstables();
    void m_flush_memtable();
    void m_compact();

public:
    LSMTree(std::string base_path);

    void set(std::string key, std::string value);
    std::string get(std::string key);
    void del(std::string key);
    
    void range_query(std::string start_key, std::string end_key);
    void close();
};

#endif
