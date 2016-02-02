 
#include "header/appNative.hpp"
#include "header/sceneManager.hpp"


int main() {
  AppNative native(640, 480, "hoge");
  native.setClearColor(Color::gray());

  SceneManager scene(&native);

  while (native.isOpen() && !native.isPushKey(GLFW_KEY_ESCAPE)) {
    native.clearWindowBuff();

    scene.run();

    native.updateEvent();
  }
}
