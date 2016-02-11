
#include "game.hpp"
#include "../sceneMaker.hpp"


Game::Game(AppNative* app) :
SceneBase(app),
font(loadAssets("rounded-l-mplus-1c-regular.ttf"))
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
  font.drawCenter(str, app->windowHalff());
}

std::shared_ptr<SceneBase> Game::nextScene(AppNative* app) {
  return sceneCreate<Title>(app);
}
