#include <iostream>
#include "object_construction.hpp"

object::object() {
  std::cout << "Called: Constructor." << std::endl;
}

void object::operator=(const object&) {
  std::cout << "Called Assignment." << std:: endl;
}

object::object(object& obj) {
  std::cout << "Called Copy Constructor." << std::endl;
}

object:: ~object() {
  std::cout << "Called Destructor." << std::endl;
}

