
#include "header/title.hpp"
#include "header/sceneMaker.hpp"
#include <iostream>


Title::Title(AppNative* app) :
SceneBase(app) {}

void Title::update() {}

void Title::draw() {
  if (app->isPushKey(GLFW_KEY_A)) {
    std::cout << "push A" << std::endl;
  }
}

std::shared_ptr<SceneBase> Title::nextScene(AppNative* app) {
  return sceneCreate<Title>(app);
}
