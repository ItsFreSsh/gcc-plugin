#include <iostream>

#include "gcc-plugin.h"

#include "tree-pass.h"
#include "context.h"
#include "basic-block.h"
#include "tree.h"
#include "print-tree.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "gimple-expr.h"

#include "function.h"
#include "process-function.h"
#include "process-block.h"
#include "process-function-parameters.h"
#include "data-type.h"

Function processFunction(function* func) {
    Function f;
    f.name = function_name(func);

    // Entry parameters
    tree param;
    for (param = DECL_ARGUMENTS(func->decl); param; param = DECL_CHAIN(param)) {
        f.insertParameter(processFunctionParameter(param));
    }

    basic_block bb;
    FOR_ALL_BB_FN(bb, func) {
        gimple_bb_info* bb_info = &bb->il.gimple;
        // Entry block
        if (bb->index == 0) {
            f.entry_block = "bb " + std::to_string(bb->index);
        }
        // Exit block
        else if (bb->index == 1) {
            f.exit_block = "bb " + std::to_string(bb->index);
        }
        // Other blocks
        else {
            BasicBlock b = processBlock(bb);
            f.insertBasicBlock(b);
        }
    }
    return f;
}