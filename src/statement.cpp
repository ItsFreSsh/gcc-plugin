#include <iostream>
#include "statement.h"
#include "util.h"

void Statement::print(unsigned int indentBy) const {
    indent(indentBy);
    std::cout << "\"stmt\": {" << std::endl;
    indentBy++;
    indent(indentBy);
    std::cout << "\"name\": \"" << name << "\"" << std::endl;
    indentBy--;
    indent(indentBy);
    std::cout << "}," << std::endl;
    loc.print(indentBy);
}