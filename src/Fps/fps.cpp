
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

  // �ݒ肵��FPS��菈���������I����
  // �����I�������������x�点��
  while(_delta >= 0) {
    current = glfwGetTime();
    delta = current - last;

    _delta = must - delta;
  }

  last = current;
}
