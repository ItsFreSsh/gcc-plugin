#include <iostream>
#include "util.h"

void indent(unsigned int indentBy) {
    for (unsigned int i = 0; i < indentBy; i++) {
        std::cout << "\t";
    }
}