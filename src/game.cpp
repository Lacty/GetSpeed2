
#include "header/game.hpp"
#include "header/debugIO.hpp"
#include "header/tweakbar.hpp"


Game::Game() {}


void Game::run() {
#if DEBUG_IO
  TwDraw();
#endif
}
