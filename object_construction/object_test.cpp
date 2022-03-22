#include <iostream>
#include "object_construction.hpp"
#include "object_construction.cpp"

int main() {
    
  object o;
  o.operator=(o);
  object();
    
  return 0;
}

