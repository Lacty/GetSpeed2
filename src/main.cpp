
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(640, 480), "GetSpeed2");
  app.setClearColor(Color::gray());

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
