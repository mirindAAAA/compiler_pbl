#include "lexer.h"
#include <regex>

std::vector<Token> tokenize(const std::string &code)
{
    std::vector<Token> tokens;

    std::regex word_regex("[A-Za-z_][A-Za-z0-9_]*");

    auto words_begin =
        std::sregex_iterator(code.begin(), code.end(), word_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        Token t;
        t.type = "IDENTIFIER";
        t.value = (*i).str();
        tokens.push_back(t);
    }

    return tokens;
}