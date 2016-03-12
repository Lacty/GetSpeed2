
#include "title.hpp"
#include "../Scene/sceneMaker.hpp"


Title::Title(AppNative* app) :
SceneBase(app) {
  std::cout << "start title" << std::endl;
}

Title::~Title() {
  std::cout << "end title" << std::endl;
}


void Title::update() {}

void Title::draw() {}


std::shared_ptr<SceneBase> Title::nextScene(AppNative *app) {
  return sceneCreate<Game>(app);
}