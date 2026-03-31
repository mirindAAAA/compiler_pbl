#include "ast_visualizer.h"
#include <fstream>
#include <iostream>

void exportASTGraph(const std::vector<ASTNode>& ast)
{
    std::ofstream file("ast.dot");

    file << "digraph AST {\n";
    file << "node [shape=ellipse, style=filled, color=lightblue];\n";

    // Root node
    file << "Program [shape=box, color=lightgreen];\n";
   
    for (size_t i = 0; i < ast.size(); i++)
    {
        file << "node" << i << " [label=\"" << ast[i].value << "\"];\n";
        file << "Program -> node" << i << ";\n";
            if(ast[i].value == "gets")
{
    file << "node" << i << " [label=\"gets\", color=red];\n";
}
    }

    file << "}\n";

    file.close();

    std::cout << "\nAST graph exported successfully: ast.dot\n";
}