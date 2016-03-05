
#include "AppNative/appNative.hpp"

// Todo: Vector: impl norm/cross/dot

int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
