
#include "sceneManager.hpp"


SceneManager::SceneManager(AppNative* app) :
app_(app) {}


void SceneManager::update() {
  scene_->update();
}

void SceneManager::draw() {
  scene_->draw();
}