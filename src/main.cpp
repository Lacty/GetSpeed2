
#include "AppNative/appNative.hpp"
#include "Scene/sceneManager.hpp"


int main() {
  AppNative app(640, 480, "GetSpeed2");
  app.setClearColor(Color::gray());

  SceneManager scene(&app);

  glfwSwapInterval(1);
  
  while(app.isOpen() && !app.isPressKey(GLFW_KEY_ESCAPE)) {
    app.clearWindowBuff();

    scene.run();

    app.updateEvent();
  }
}
