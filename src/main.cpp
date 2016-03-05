
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "GetSpeed2");
  app.setClearColor(Color::gray());

  Media media(loadAsset("sound.wav"));
  media.setVolume(1.0f)
    ->play();

  while (app.isOpen()) {
    app.begin();

    app.end();
  }
}
