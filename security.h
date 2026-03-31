#ifndef SECURITY_H
#define SECURITY_H

#include "lexer.h"
#include <string>
#include <vector>

void detectUnsafeFunctions(const std::vector<Token>& tokens);
void detectBufferOverflow(const std::string &code);
void detectInfiniteLoops(const std::string &code);
void detectNullPointer(const std::string &code);
void detectOWASPPatterns(const std::string &code);
#endif