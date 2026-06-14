#include "lsmtree.h"
// basically if lsmtree header file wasnt defined run
// the following (the entire header file) - preprocessing
// directives

// class definitions and function declarations go 
// in header files

// mmmm okay so it looks like since all of these are
// member functions of a class you gotta specify them
// as such with LSMTree::(method name)

void LSMTree::m_load_sstables() {
    std::cout << "dummy\n";
}

void LSMTree::m_flush_memtable() {
    std::cout << "dummy\n";
}

void LSMTree::m_compact() {
    std::cout << "dummy\n";
}

LSMTree::LSMTree(std::string base_path):
    // how do i construct a path Lol Lol Lol
    m_base_path {base_path} // python does this iwth Path()?
{
}

void LSMTree::set(std::string key, std::string value) {
    std::cout << "dummy\n";
}

std::string LSMTree::get(std::string key) {
    return key;
}

void LSMTree::del(std::string key) {
    // using a lock, add a "delete" log to the WAL
    // add a tombstone to the memtable
    std::cout << "dummy\n";
}

void LSMTree::range_query(std::string start_key, std::string end_key) {
    std::cout << "dummy\n";
};

void LSMTree::close() {
    std::cout << "dummy\n";
    // checkpoint on wal - ensure its up to date
};