
#include "game.hpp"
#include "../sceneMaker.hpp"


Game::Game(AppNative* app) :
SceneBase(app),
font(loadAssets("rounded-l-mplus-1c-regular.ttf"))
{
  std::cout << "start Game" << std::endl;

  angle = 0;
  twBar = TwNewBar("game");
  TwAddVarRW(twBar, "angle", TW_TYPE_FLOAT, &angle, "");
  airframe = Airframe(Airframe::Type::Normal,
                      Airframe::State::Ready);

  app->setCamPos(vec3f(0, 1, 4));
  app->setCamTarget(vec3f(0, 0, 0));

  app->startFade(Fade::Type::In);
}

Game::~Game() {
  std::cout << "end Game" << std::endl;
}


void Game::update() {
  if(app->isPressKey(GLFW_KEY_W)) {
    airframe.accel();
  }
  if(app->isPressKey(GLFW_KEY_A)) {
    airframe.handle(Airframe::Left);
  }
  if(app->isPressKey(GLFW_KEY_D)) {
    airframe.handle(Airframe::Right);
  }
  airframe.update();
  stage.update();
}

void Game::draw() {
  std::string str("- Game -");
  font.setSize(50.0f * app->getWindowScale());
  font.drawCenter(str, app->windowHalff());
  
  stage.draw();
  airframe.draw();
}

std::shared_ptr<SceneBase> Game::nextScene(AppNative* app) {
  return sceneCreate<Title>(app);
}
