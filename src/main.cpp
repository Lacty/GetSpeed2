
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(640, 480), "GetSpeed2");

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
