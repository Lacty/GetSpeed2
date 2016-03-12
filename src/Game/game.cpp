
#include "game.hpp"
#include "../Scene/sceneMaker.hpp"
#include "../Title/title.hpp"


Game::Game(AppNative* app) :
SceneBase(app) {
  std::cout << "start game" << std::endl;
}

Game::~Game() {
  std::cout << "end game" << std::endl;
}


void Game::update() {}

void Game::draw() {}


std::shared_ptr<SceneBase> Game::nextScene(AppNative *app) {
  return sceneCreate<Title>(app);
}