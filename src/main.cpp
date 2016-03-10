
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());

  GLfloat a[] = { 0, 1, 2 };
  std::cout << pToVec3<float>(a) << std::endl;

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
