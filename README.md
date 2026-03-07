# compiler_pbl
# Secure Code Analyzer

A compiler-inspired static analysis tool that detects insecure coding patterns in C programs.

## Features

• Lexical Analysis (Tokenization)
• AST Construction
• Detection of unsafe functions
• Buffer overflow detection
• Infinite loop detection
• Null pointer detection
• Security report generation

## Technologies

C++
Regex
Static analysis

## How to Run

Compile:

g++ main.cpp lexer.cpp parser.cpp security.cpp report.cpp -o analyzer

Run:

./analyzer

## Example Output

⚠ Unsafe function detected: gets()
⚠ Possible buffer overflow
⚠ Infinite loop detected
⚠ Null pointer usage
