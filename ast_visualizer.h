#ifndef AST_VISUALIZER_H
#define AST_VISUALIZER_H

#include "parser.h"
#include <vector>

void exportASTGraph(const std::vector<ASTNode>& ast);

#endif