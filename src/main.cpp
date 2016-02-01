
#include <iostream>
#include "header/debugIO.hpp"


int main() {
#if DEBUG_IO
  std::cout << "debug mode" << std::endl;
#else
  std::cout << "release mode" << std::endl;
#endif
}
