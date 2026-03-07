#include "parser.h"
#include <iostream>

std::vector<ASTNode> buildAST(const std::vector<Token>& tokens)
{
    std::vector<ASTNode> ast;

    for (auto &t : tokens)
    {
        ASTNode node;
        node.type = t.type;
        node.value = t.value;
        ast.push_back(node);
    }

    return ast;
}

void printAST(const std::vector<ASTNode>& ast)
{
    std::cout << "\nAST Representation:\n";

    for (auto &node : ast)
    {
        std::cout << node.type << " -> " << node.value << std::endl;
    }
}