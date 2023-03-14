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
    std::cout << "\t\t" << "\"" << name << "\": {" << std::endl;
    std::cout << "\t\t\t" << "\"succ\": [";
    for (size_t i = 0; i < succ.size(); i++) {
        std::cout << "\"" << succ[i] << "\"";
        if (i < succ.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "], " << std::endl;
    std::cout << "\t\t\t" << "\"stmts\": [" << std::endl;
    for (size_t i = 0; i < statements.size(); i++) {
        std::cout << "\t\t\t\t" << "{" << std::endl;
        statements[i].print();
        std::cout << "\t\t\t\t" << "}";
        if (i < statements.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "\t\t\t" << "]" << std::endl;
    std::cout << "\t\t" << "}";
}