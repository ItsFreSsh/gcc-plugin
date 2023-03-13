#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <vector>
#include "basic-block.h"

class Function {
public:
    std::string name;
    std::string entry_block;
    std::string exit_block;
    std::vector<BasicBlock> blocks;
    void insertBasicBlock(const BasicBlock& bb);
    void print() const;
};

#endif