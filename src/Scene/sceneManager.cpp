
#include "sceneManager.hpp"
#include "sceneMaker.hpp"

#include "../Title/title.hpp"
#include "../Game/game.hpp"


SceneManager::SceneManager(AppNative* app) :
app_(app) {
  scene_ = sceneCreate<Title>(app);
}


void SceneManager::update() {
  scene_->update();
}

void SceneManager::draw() {
  scene_->draw();
}