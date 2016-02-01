
#include "header/game.hpp"
#include "header/debugIO.hpp"
#include "header/tweakbar.hpp"

#include "header/title.hpp"


Game::Game(AppNative* app) :
app(app) {
  scene = sceneCreate<Title>(app);
}


void Game::update() {
  scene->update();
  if (scene->shouldClose()) { scene = scene->nextScene(app); }
}

void Game::draw() {
  scene->draw();
}

void Game::run() {
  update();
  draw();

#if DEBUG_IO
  TwDraw();
#endif
}
