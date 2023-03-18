#include <iostream>
#include <vector>
#include <string>

#include "json.h"
#include "function.h"

void Json::insertFunction(const Function& f) {
    functions.push_back(f);
}

void Json::print(unsigned int indentBy) const {
    std::cout << "{" << std::endl;
    for (int i = 0; i < functions.size(); i++) {
        functions[i].print(indentBy + 1);
        if (i < functions.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}