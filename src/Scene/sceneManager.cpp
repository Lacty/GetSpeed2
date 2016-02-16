
#include "sceneManager.hpp"


SceneManager::SceneManager(AppNative* app) :
app(app) {
  scene = sceneCreate<Title>(app);
}


void SceneManager::update() {
  scene->update();
}

void SceneManager::draw() {
  scene->draw();

  TwDraw();

  // ƒV[ƒ“Ø‚è‘Ö‚¦
  if(scene->shouldClose() && app->isFinishFade()) {
    scene = scene->nextScene(app);
  }
}
