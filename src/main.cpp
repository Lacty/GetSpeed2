 
#include <iostream>
#include <GLFW/glfw3.h>

#include "header/debugIO.hpp"
#include "header/appNative.hpp"
#include "header/game.hpp"

#include "header/timer.hpp"


int main() {
  AppNative native(640, 480, "hoge");
  native.setClearColor(Color::gray());

  Game game;
  Timer timer;

  while (native.isOpen() && !native.isPushKey(GLFW_KEY_ESCAPE)) {
    native.clearWindowBuff();

    game.update();

    if (native.isPushKey(GLFW_KEY_S)) {
      timer.stop();
    }
    if (native.isPushKey(GLFW_KEY_R)) {
      timer.start();
    }
    if (native.isPushKey(GLFW_KEY_E)) {
      timer.end();
    }

    std::cout << timer.getCurrentTime() << std::endl;

#if DEBUG_IO
    TwDraw();
#endif
    native.updateEvent();
  }
}
