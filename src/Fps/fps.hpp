
#pragma once
#include <GLFW/glfw3.h>


class Fps {
private:
  double current;
  double last;

public:
  Fps();

  double get();
};
