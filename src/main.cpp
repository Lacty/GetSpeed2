
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "GetSpeed2");
  app.setClearColor(Color::gray());

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
