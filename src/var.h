#ifndef VAR_H
#define VAR_H

#include <string>
#include "data-type.h"

class Var {
public:
    std::string name;
    DataType* type;
    void print(unsigned int indent) const;
};

#endif