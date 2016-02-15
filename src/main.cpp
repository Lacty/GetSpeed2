
#include "AppNative/appNative.hpp"
#include "Scene/sceneManager.hpp"


int main() {
  AppNative app(800, 480, "GetSpeed2");
  app.setClearColor(Color::gray());

  SceneManager scene(&app);

  while(app.isOpen() && !app.isPressKey(GLFW_KEY_ESCAPE)) {
    app.clearWindowBuff();

    scene.run();

    app.updateEvent();
  }
}
