#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>
#include <string>

struct ASTNode
{
    std::string type;
    std::string value;
};

std::vector<ASTNode> buildAST(const std::vector<Token>& tokens);
void printAST(const std::vector<ASTNode>& ast);

#endif