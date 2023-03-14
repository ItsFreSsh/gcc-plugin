#include <iostream>
#include "loc.h"

void Loc::print() const {
    std::cout << "\t\t\t\t\t\"loc\": {";
    std::cout << "\"file\": " << "\"" << file << "\"" << ", " << "\"line\": " << line << " }" <<  std::endl;
}