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

Function processFunction(function *func) {
    Function f;
    f.name = function_name(func);

    // Entry parameters
    /*tree param;
    for (param = DECL_ARGUMENTS(func->decl); param; param = DECL_CHAIN(param)) {
		//std::string param_type = get_parameter_type(TREE_TYPE(param));
		param_to_add["name"] = get_name(param);
		param_to_add["type"] = get_decl_type(TREE_TYPE(param));
		//get_decl_type(TREE_TYPE(param));
		output[function_name(fun)]["entry_parameters"].append(param_to_add);
		++nparams;
	}*/

    basic_block bb;
    FOR_ALL_BB_FN(bb, func) {
        gimple_bb_info *bb_info = &bb->il.gimple;
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