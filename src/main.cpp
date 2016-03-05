
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "GetSpeed2");
  app.setClearColor(Color::gray());

  std::cout << app.rand(10) << std::endl;
  std::cout << app.rand(10.0f) << std::endl;
  std::cout << app.rand(10.0) << std::endl;
  std::cout << app.rand(5) << std::endl;
  std::cout << app.rand(5.3) << std::endl;
  std::cout << app.rand(0.1) << std::endl;

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
