#include <iostream>
#include "function.h"
#include "basic-block.h"

void Function::insertBasicBlock(const BasicBlock& bb) {
    blocks.push_back(bb);
}

void Function::print() const{
    // Print function
}