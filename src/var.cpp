#include <iostream>
#include "var.h"
#include "data-type.h"
#include "util.h"

void Var::print(unsigned int indentBy) const {
    indent(indentBy);
    std::cout << "\"" << name << "\": {" << std::endl;
    type->print(indentBy + 1);
    indent(indentBy);
    std::cout << "}";
}