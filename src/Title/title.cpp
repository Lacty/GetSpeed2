
#include "title.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Game/game.hpp"


Title::Title(AppNative* app) :
SceneBase(app, Fade(Fade::Type::In)),
font(loadAsset("rounded-l-mplus-1c-regular.ttf")) {
  font.setSize(50);
  std::cout << "start title" << std::endl;
}

Title::~Title() {
  std::cout << "end title" << std::endl;
}


void Title::update() {
  if (app_->isPushKey(GLFW_KEY_W)) {
    is_finish_ = true;
  }
}

void Title::draw() {
  font.draw("Title", Vec2f(app_->windowCenter()));
}


std::shared_ptr<SceneBase> Title::nextScene(AppNative *app) {
  return sceneCreate<Game>(app);
}