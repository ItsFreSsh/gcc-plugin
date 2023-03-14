#ifndef JSON_H
#define JSON_H

#include <vector>
#include <string>

class Json {
public:
    std::vector<Function> functions;
    void insertFunction(const Function& f);
    void print() const;
};

#endif