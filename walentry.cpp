#ifndef WALENTRY_H
#define WALENTRY_H

#include "walentry.h"
#include <string>
#include <iostream>

// this is the source file - #include the header
// and then work on the method DEFINITIONS
WALEntry::WALEntry(std::string new_operation, std::string new_key, std::string new_value)
    : operation {new_operation}
    , key {new_key}
    , value {new_value}
{
}

#endif