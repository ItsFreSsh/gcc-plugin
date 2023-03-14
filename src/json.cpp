#include <iostream>
#include <vector>
#include <string>
#include "function.h"

void Json::insertFunction(const Function& f) {
    functions.push_back(f);
}

void Json::print() const {
    std::cout << "{" << std::endl;
    for (int i = 0; i < functions.size(); i++) {
        functions[i].print();
        if (i < functions.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}