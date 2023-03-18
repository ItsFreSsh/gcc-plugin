#include <iostream>
#include "basic-block.h"
#include "statement.h"
#include "util.h"

void BasicBlock::addSuccessor(const std::string& successorName) {
    succ.push_back(successorName);
}

void BasicBlock::insertStatement(const Statement& stmt) {
    statements.push_back(stmt);
}

void BasicBlock::print(unsigned int indentBy) const {
    indent(indentBy);
    std::cout << "\"" << name << "\": {" << std::endl;
    indentBy++;
    indent(indentBy);
    std::cout << "\"succ\": [";
    for (size_t i = 0; i < succ.size(); i++) {
        std::cout << "\"" << succ[i] << "\"";
        if (i < succ.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "], " << std::endl;
    indent(indentBy);
    std::cout << "\"stmts\": [" << std::endl;
    indentBy++;
    for (size_t i = 0; i < statements.size(); i++) {
        indent(indentBy);
        std::cout << "{" << std::endl;
        statements[i].print(indentBy);
        indent(indentBy);
        std::cout << "}";
        if (i < statements.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    indentBy--;
    indent(indentBy);
    std::cout << "]" << std::endl;
    indentBy--;
    indent(indentBy);
    std::cout << "}";
}