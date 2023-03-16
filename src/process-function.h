#ifndef PROCESS_FUNCTION_H
#define PROCESS_FUNCTION_H

#include "gcc-plugin.h"

#include "tree-pass.h"
#include "context.h"
#include "basic-block.h"
#include "tree.h"
#include "print-tree.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "gimple-expr.h"

#include <string>

Function processFunction(function *func);

#endif