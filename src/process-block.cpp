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
#include "gimple-pretty-print.h"

#include "statement.h"
#include "process-block.h"
#include "basic-block.h"
#include "process-statement.h"

BasicBlock processBlock(basic_block bb) {
    BasicBlock b;
	Statement stmt;
    gimple_bb_info *bb_info = &bb->il.gimple;
	gimple_stmt_iterator gsi;

	b.name = "bb " + std::to_string(bb->index);

    edge e;
	edge_iterator ei;

	// Add all block successors
	FOR_EACH_EDGE(e, ei, bb->succs) {
		basic_block dest = e->dest;
        b.addSuccessor("bb " + std::to_string(dest->index));
	}

	for (gsi = gsi_start(bb_info->seq); !gsi_end_p(gsi); gsi_next(&gsi)) {
		gimple* g = gsi_stmt(gsi);
		stmt = processStatement(g);
		b.insertStatement(stmt);
		//print_gimple_stmt(stdout, g, 0, (dump_flags_t)0);
	}

    return b;
}