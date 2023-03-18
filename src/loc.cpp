#include <iostream>
#include "loc.h"
#include "util.h"

void Loc::print(unsigned int indentBy) const {
    indent(indentBy);
    std::cout << "\"loc\": {";
    std::cout << "\"file\": " << "\"" << file << "\"" << ", " << "\"line\": " << line << " }" << std::endl;
}