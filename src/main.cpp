
#include "AppNative/appNative.hpp"
#include "Scene/sceneManager.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());
  
  SceneManager scene(&app);

  while (app.isOpen()) {
    scene.run();
    drawLine(Vec2f(0, 0), Vec2f(1.f, .5f));
  }
}
