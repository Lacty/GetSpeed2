
#pragma once
#include <GLFW/glfw3.h>


class Fps {
private:
  double current;
  double last;
  int fps;
  double must;

public:
  Fps(const int _fps = 60);

  void setFps(const int _fps);
  void swapInterval();
};
