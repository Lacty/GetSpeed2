
#include "AppNative/appNative.hpp"
#include <deque>

int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());

  int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::cout << toVec3<int>(&a[0], 2);

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
