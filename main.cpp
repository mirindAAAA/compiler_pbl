#include <iostream>
#include <fstream>
#include <sstream>
#include "pdf_report.h"
#include "lexer.h"
#include "parser.h"
#include "security.h"
#include "report.h"
#include "ast_visualizer.h"

int main()
{
    std::ifstream file("test.cpp");

    if (!file.is_open())
    {
        std::cout << "Error opening file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();

    printHeader();

    auto tokens = tokenize(code);

    std::cout << "\nTokens Found:\n";
    for (auto &t : tokens)
        std::cout << t.value << std::endl;

    auto ast = buildAST(tokens);
    printAST(ast);
    exportASTGraph(ast);
    detectUnsafeFunctions(tokens);
    detectBufferOverflow(code);
    detectInfiniteLoops(code);
    detectNullPointer(code);
    detectOWASPPatterns(code);
    printFooter();
    generateReport();
}