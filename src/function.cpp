#include <iostream>
#include "function.h"
#include "basic-block.h"

void Function::insertBasicBlock(const BasicBlock& bb) {
    basic_blocks.push_back(bb);
}

void Function::print() const{
    // Print function
}