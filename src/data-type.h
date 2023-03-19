#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <string>

class DataType {
public:
    std::string name;
    size_t sizeOf;
    size_t precision;
    long long int min;
    unsigned long long int max;
    bool signedness;
    DataType* type; // pointer to another DataType object for pointed-to type
    void print(unsigned int indentBy) const;
};

#endif