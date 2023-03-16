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
#include <real.h>
#include "statement.h"

Statement processStatement(gimple* g) {
    Statement stmt;

    // Statement location
    if(gimple_filename(g)) {
        stmt.loc.file = gimple_filename(g);
	}
    if(gimple_lineno(g)) {
        stmt.loc.line = gimple_lineno(g);
    }

    stmt.name = gimple_code_name[gimple_code(g)];

    
    return stmt;
}