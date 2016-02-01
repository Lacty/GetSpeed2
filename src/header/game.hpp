
#pragma once
#include "appNative.hpp"
#include <chrono>


class Game {
private:
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::duration<double, std::ratio<1>>   duration;

  double mticks();

public:
  Game();

  void update();
  void draw();
};
