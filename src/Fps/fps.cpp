
#include "fps.hpp"
#include <thread>
#include <chrono>
#include <iostream>


Fps::Fps(const int _fps) :
current(0.0),
last(0.0),
fps(_fps)
{
  setFps(_fps);
}


void Fps::setFps(const int _fps) {
  fps = _fps;
  must = double(1) / fps;
}

void Fps::swapInterval() {
  current = glfwGetTime();
  auto delta = current - last;

  auto must = (double)1 / fps;
  auto _delta = must - delta;

  // 設定したFPSより処理が早く終われば
  // 早く終わった分処理を遅らせる
  while(_delta >= 0) {
    current = glfwGetTime();
    delta = current - last;

    _delta = must - delta;
  }

  last = current;
}
