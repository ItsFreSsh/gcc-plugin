#include <iostream>
#include "function.h"
#include "basic-block.h"

void Function::insertBasicBlock(const BasicBlock& bb) {
    blocks.push_back(bb);
}

void Function::print() const{
    std::cout << "\t\"" << name << "\": {" << std::endl;
    std::cout << "\t\t\"entry_block\": \"" << entry_block << "\"," << std::endl;
    std::cout << "\t\t\"exit_block\": \"" << exit_block << "\"," << std::endl;
    for (int i = 0; i < blocks.size(); i++) {
        blocks[i].print();
        if (i < blocks.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "\t}";
}