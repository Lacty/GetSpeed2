
#include "header/sceneManager.hpp"
#include "header/debugIO.hpp"
#include "header/tweakbar.hpp"

#include "header/title.hpp"


SceneManager::SceneManager(AppNative* app) :
app(app) {
  scene = sceneCreate<Title>(app);
}


void SceneManager::update() {
  scene->update();
  if (scene->shouldClose()) { scene = scene->nextScene(app); }
}

void SceneManager::draw() {
  scene->draw();
}

void SceneManager::run() {
  update();
  draw();

#if DEBUG_IO
  TwDraw();
#endif
}
