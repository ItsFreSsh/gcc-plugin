#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <string>

class DataType {
public:
    std::string name;
    size_t sizeOf;
    size_t precision;
    size_t min;
    size_t max;
    bool signedness;
    DataType* type; // pointer to another DataType object for pointed-to type
    void print(unsigned int indentBy) const;
};

#endif