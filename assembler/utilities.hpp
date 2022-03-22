#ifndef utilities_
#define utilities_
#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "../string/string.hpp"

void toPostfix(std::ifstream& in, std::ostream& out); 
void toAssembly(std::ifstream& in, std::ostream& out);
std::string intToString(int);
std::string getOperator(const std::string& op);
std::string getToken(std::ifstream& in); 
#endif