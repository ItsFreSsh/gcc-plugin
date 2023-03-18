#include <iostream>
#include "function.h"
#include "basic-block.h"
#include "var.h"
#include "util.h"

void Function::insertBasicBlock(const BasicBlock& bb) {
    blocks.push_back(bb);
}

void Function::insertParameter(const Var& param) {
    parameters.push_back(param);
}

void Function::print(unsigned int indentBy) const {
    indent(indentBy);
    std::cout << "\"" << name << "\": {" << std::endl;
    indentBy++;
    // Function parameters
    indent(indentBy);
    std::cout << "\"entry_parameters\": {" << std::endl;
    indentBy++;
    for (int i = 0; i < parameters.size(); i++) {
        parameters[i].print(indentBy);
        if (i < parameters.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    indentBy--;
    indent(indentBy);
    std::cout << "}," << std::endl;
    indent(indentBy);
    std::cout << "\"entry_block\": \"" << entry_block << "\"," << std::endl;
    indent(indentBy);
    std::cout << "\"exit_block\": \"" << exit_block << "\"," << std::endl;
    for (int i = 0; i < blocks.size(); i++) {
        blocks[i].print();
        if (i < blocks.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    indentBy--;
    indent(indentBy);
    std::cout << "}";
    indentBy--;
}