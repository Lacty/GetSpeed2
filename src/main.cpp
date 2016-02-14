
#include "AppNative/appNative.hpp"
#include "Scene/sceneManager.hpp"


template<typename T>
class PP {
public:
  T v;
};

int main() {
  AppNative app(800, 480, "GetSpeed2");
  app.setClearColor(Color::gray());

  SceneManager scene(&app);
  
  PP<std::vector<float>> p;
  p.v.push_back(1);

  while(app.isOpen() && !app.isPressKey(GLFW_KEY_ESCAPE)) {
    app.clearWindowBuff();

    scene.run();

    app.updateEvent();
  }
}
