
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(640, 480), "GetSpeed2");
  app.setClearColor(Color::gray());

  Font font(loadAssets("rounded-l-mplus-1c-regular.ttf"));
  font.setSize(100);

  while (app.isOpen()) {
    app.begin();

    font.drawCenter("Hoge", app.windowCenter());

    app.end();
  }
}
