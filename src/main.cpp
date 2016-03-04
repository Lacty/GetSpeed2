
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(640, 480), "GetSpeed2");
  app.setClearColor(Color::gray());

  Font font("../../assets/rounded-l-mplus-1c-regular.ttf");
  font.setSize(50);

  while (app.isOpen()) {
    app.begin();

    font.drawCenter("hoge", app.windowCenter());

    app.end();
  }
}
