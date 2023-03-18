#include <iostream>
#include "data-type.h"
#include "util.h"

void DataType::print(unsigned int indentBy) const {
    indent(indentBy);
    std::cout << "\"name" << "\": \"" << name << "\"," << std::endl;
    indent(indentBy);
    std::cout << "\"sizeOf" << "\": \"" << sizeOf << "\"," << std::endl;
    indent(indentBy);
    std::cout << "\"precision" << "\": \"" << precision << "\"," << std::endl;
    indent(indentBy);
    std::cout << "\"min" << "\": \"" << min << "\"," << std::endl;
    indent(indentBy);
    std::cout << "\"max" << "\": \"" << max << "\"," << std::endl;
    indent(indentBy);
    std::cout << "\"signed" << "\": \"" << signedness << "\"";
    if (type != nullptr) {
        std::cout << "," << std::endl;
        indent(indentBy);
        std::cout << "\"type\": {" << std::endl;
        type->print(indentBy + 1);
        indent(indentBy);
        std::cout << "}" << std::endl;
        indentBy--;
    } else {
        std::cout << std::endl;
        indentBy--;
    }
}
