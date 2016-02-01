
#include "header/game.hpp"
#include <iostream>


Game::Game() {
  start = std::chrono::high_resolution_clock::now();
}

double Game::mticks() {
  duration = std::chrono::high_resolution_clock::now() - start;
  return duration.count();
}

void Game::update() {}

void Game::draw() {}
