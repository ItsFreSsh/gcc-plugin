#ifndef LOC_H
#define LOC_H

#include <string>

class Loc {
public:
    std::string file;
    int line;
    void print(unsigned int indentBy) const;
};

#endif