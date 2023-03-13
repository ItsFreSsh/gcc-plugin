#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include <vector>
#include "statement.h"

class BasicBlock {
public:
    std::vector<std::string> succ;
    std::vector<Statement> statements;
    void insertStatement(const Statement &stmt);
    void print() const;
};

#endif