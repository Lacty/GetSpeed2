
#include "AppNative/appNative.hpp"
#include "Scene/sceneManager.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());
  
  SceneManager scene(&app);
  
  float arr[] = { 1, 2, 3, 4, 5 };
  Vec2f p = convertArrayToVec<Vec2f>(&arr[1]);
  
  std::cout << p << std::endl;

  while (app.isOpen()) {
    scene.run();
  }
}
