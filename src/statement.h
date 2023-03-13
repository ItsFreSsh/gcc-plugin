#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <vector>
#include "loc.h"

class Statement {
public:
    Loc loc;
    std::string name;
    /*std::string comparison;
    std::vector<std::string> label;
    std::vector<std::string> in;
    std::vector<std::string> out;
    std::string function;
    std::string nested;
    std::string str;*/
    void print() const;
};

#endif