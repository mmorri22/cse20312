#ifndef BALANCED_H
#define BALANCED_H

// include C++ libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define VECTOR std::vector
#define STRING std::string 
#define STACK std::stack

// declare function that obtains code from file
void getCode(IFSTREAM& CodeFile, VECTOR< STRING >& codeVector);

// declare function that checks if code is balanced
bool checkCode(VECTOR< STRING >& codeVector);

#endif
