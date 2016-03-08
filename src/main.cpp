
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());

  Font font(loadAsset("rounded-l-mplus-1c-regular.ttf"));
  font.setSize(100);

  while (app.isOpen()) {
    app.begin();

    font.draw("hoge", Vec2f::zero());

    app.end();
  }
}
