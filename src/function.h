#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <vector>
#include "basic-block.h"
#include "var.h"

class Function {
public:
    std::string name;
    std::string entry_block;
    std::string exit_block;
    std::vector<BasicBlock> blocks;
    std::vector<Var> parameters;
    void insertBasicBlock(const BasicBlock& bb);
    void insertParameter(const Var& param);
    void print(unsigned int indent) const;
};

#endif