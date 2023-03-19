#include "gcc-plugin.h"

#include "tree-pass.h"
#include "context.h"
#include "basic-block.h"
#include "tree.h"
#include "print-tree.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "gimple-expr.h"

#include <iostream>

#include "process-function-parameters.h"
#include "var.h"
#include "data-type.h"

DataType* getTypeInfo(tree t) {
    DataType* type = new DataType();
    type->name = IDENTIFIER_POINTER(DECL_NAME(TYPE_NAME(TREE_TYPE(t))));
    type->precision = TYPE_PRECISION(TREE_TYPE(t));
    type->signedness = TYPE_SIGN(TREE_TYPE(t)) == 0 ? true : false;
    type->sizeOf = TREE_INT_CST_LOW(TYPE_SIZE_UNIT(TREE_TYPE(t)));
    if (TREE_CODE(TREE_TYPE(t)) == INTEGER_TYPE) {
        type->max = TREE_INT_CST_LOW(TYPE_MAX_VALUE(TREE_TYPE(t)));
        type->min = TREE_INT_CST_LOW(TYPE_MIN_VALUE(TREE_TYPE(t)));
    }
    type->type = nullptr;
    return type;
}

DataType* processPointer(tree t) {
    DataType* type = new DataType();
    type->name = "pointer";
    if (TREE_CODE(TREE_TYPE(t)) == POINTER_TYPE) {
        DataType* newType = processPointer(TREE_TYPE(t));
        type->type = newType;
    } else {
        type = getTypeInfo(t);
    }
    return type;
}

Var processFunctionParameter(tree t) {
    Var var;
    var.name = get_name(t);
    // TODO: ensure memory dealloc
    DataType* type = new DataType();
    // node is a pointer
    if (TREE_CODE(TREE_TYPE(t)) == POINTER_TYPE) {
        type->name = "pointer";
        DataType* newType = processPointer(TREE_TYPE(t));
        type->type = newType;
    } else {
        type = getTypeInfo(t);
    }
    var.type = type;
    return var;
}