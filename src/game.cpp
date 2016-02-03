
#include "header/game.hpp"
#include "header/sceneMaker.hpp"


Game::Game(AppNative* app) :
SceneBase(app),
font("assets/rounded-l-mplus-1c-regular.ttf")
{
  font.setSize(50);
}

void Game::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
  }
}

void Game::draw() {
  std::string str("- Game -");
  font.drawCenter(str, vec2f(app->windowSize().x() * 0.5f,
                             app->windowSize().y() * 0.5f));
}

std::shared_ptr<SceneBase> Game::nextScene(AppNative* app) {
  return sceneCreate<Title>(app);
}
