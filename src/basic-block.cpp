#include <iostream>
#include "basic-block.h"
#include "statement.h"

void BasicBlock::addSuccessor(const std::string& successorName) {
    succ.push_back(successorName);
}

void BasicBlock::insertStatement(const Statement& stmt) {
    statements.push_back(stmt);
}

void BasicBlock::print() const{
    // Print basic block
}