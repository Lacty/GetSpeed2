
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());

  float piyo = 0.0f;
  TwBar* twBar = TwNewBar("Test");
  TwAddVarRW(twBar, "piyo", TW_TYPE_FLOAT, &piyo, "");

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
