
#include "title.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Game/game.hpp"


Title::Title(AppNative* app) :
SceneBase(app, Fade(Fade::Type::In)),
font_(loadAsset("rounded-l-mplus-1c-regular.ttf")),
media_(loadAsset("sound2.wav")),
visualizer_(&media_) {
  font_.setSize(50);
  media_.setVolume(1.0)
    .enableLoop();
  visualizer_.setPos(Vec2f(0, 0))
    .setSize(Vec2f(600, 200))
    .setHeightUpper(200)
    .setHeightLower(1)
    .setSplitNum(50)
    .setLineWidth(5);
  std::cout << "start title" << std::endl;
}

Title::~Title() {
  std::cout << "end title" << std::endl;
}


void Title::update() {
  if (app_->isPushKey(GLFW_KEY_W)) { is_finish_ = true; }
  if (app_->isPushKey(GLFW_KEY_A)) { media_.play(); }
  if (app_->isPushKey(GLFW_KEY_S)) { media_.stop(); }
  if (app_->isPushKey(GLFW_KEY_D)) { media_.pause(); }
  if (app_->isPushKey(GLFW_KEY_F)) { media_.setOffset(100.0f); }
}

void Title::draw() {
  font_.draw("Title", Vec2f(app_->windowCenter()));
  visualizer_.draw();
}


std::shared_ptr<SceneBase> Title::nextScene(AppNative *app) {
  return sceneCreate<Game>(app);
}