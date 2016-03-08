
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());

  int i = 0;

  while (app.isOpen()) {
    app.begin();

    i++;
    if (i > 60) {
      std::cout << i << std::endl;
      i = 0;
    }

    app.end();
  }
}
