#include <iostream>
#include "statement.h"

void Statement::print() const{
    std::cout << "\t\t\t\t\t" << "\"stmt\": {" << std::endl;
    std::cout << "\t\t\t\t\t}," << std::endl;
    loc.print();
}