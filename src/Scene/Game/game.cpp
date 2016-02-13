
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
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
    app->startFade(Fade::Type::Out);
  }
  font.setSize(50.0f * app->getWindowScale());
}

void Game::draw() {
  std::string str("- Game -");
  //font.drawCenter(str, app->windowHalff());

  glPushMatrix();
  glRotatef(angle, 0, 1, 0);
  airframe.draw();
  glPopMatrix();
}

std::shared_ptr<SceneBase> Game::nextScene(AppNative* app) {
  return sceneCreate<Title>(app);
}
