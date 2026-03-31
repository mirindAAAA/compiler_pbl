#include "security.h"
#include <iostream>
#include <regex>
#include <set>
#include <vector>
void detectUnsafeFunctions(const std::vector<Token>& tokens)
{
    std::set<std::string> unsafe = {"gets", "strcpy", "sprintf"};

    for (auto &t : tokens)
    {
        if (unsafe.count(t.value))
        {
            std::cout << "\n⚠ Unsafe function detected: " << t.value << std::endl;
            std::cout << "Suggested fix: Use safer alternative.\n";
        }
    }
}

void detectBufferOverflow(const std::string &code)
{
    std::regex pattern("char\\s+(\\w+)\\[(\\d+)\\]");
    std::smatch match;

    if (std::regex_search(code, match, pattern))
    {
        std::cout << "\n⚠ Possible buffer declaration detected\n";
        std::cout << "Array: " << match[1] << " Size: " << match[2] << std::endl;
    }
}

void detectInfiniteLoops(const std::string &code)
{
    if (code.find("while(1)") != std::string::npos)
    {
        std::cout << "\n⚠ Potential infinite loop detected\n";
    }
}

void detectNullPointer(const std::string &code)
{
    if (code.find("NULL") != std::string::npos)
    {
        std::cout << "\n⚠ Null pointer usage detected\n";
    }
}

void detectOWASPPatterns(const std::string &code)
{
    std::vector<std::pair<std::string, std::string>> patterns = {

        {"gets\\s*\\(", "Unsafe input function (gets) → Buffer overflow risk"},
        {"strcpy\\s*\\(", "Use of strcpy → Potential buffer overflow"},
        {"sprintf\\s*\\(", "Use of sprintf → Possible overflow"},
        {"scanf\\s*\\(\"%s\"", "scanf with %s → Buffer overflow risk"},
        {"system\\s*\\(", "Use of system() → Command injection risk"},
        {"rand\\s*\\(", "Weak randomness (rand) → Not secure for crypto"},
        {"malloc\\s*\\(", "Dynamic memory allocation → Check for leaks"},
        {"free\\s*\\(", "Manual memory free → Risk of double free"},
        {"while\\s*\\(1\\)", "Infinite loop detected"},
        {"NULL", "Null pointer usage → Risk of dereference"}
    };

    std::cout << "\n--- OWASP Pattern Scan ---\n";

    for (auto &p : patterns)
    {
        std::regex pattern(p.first);

        if (std::regex_search(code, pattern))
        {
            std::cout << "⚠ " << p.second << std::endl;
        }
    }
}