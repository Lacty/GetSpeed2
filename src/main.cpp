
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(100, 100), "test");
  Rectf rect(50, 10);
  std::cout << rect << std::endl;
}
