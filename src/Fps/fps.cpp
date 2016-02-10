
#include "fps.hpp"


Fps::Fps() :
current(0.0),
last(0.0) {}


double Fps::get() {
  current = glfwGetTime();
  auto delta = current - last;

  auto fps = 1.0 / delta;
  
  last = current;
  return fps;
}
