
#include "header/title.hpp"
#include "header/sceneMaker.hpp"


Title::Title(AppNative* app) :
SceneBase(app),
font("assets/rounded-l-mplus-1c-regular.ttf")
{
  font.setSize(50);
}


void Title::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
  }
}

void Title::draw() {
  std::string str("- Title -");
  font.drawCenter(str, vec2f(app->windowSize().x() * 0.5f,
                             app->windowSize().y() * 0.5f));
}

std::shared_ptr<SceneBase> Title::nextScene(AppNative* app) {
  return sceneCreate<Game>(app);
}
