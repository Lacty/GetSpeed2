 
#include <iostream>
#include <GLFW/glfw3.h>

#include "header/appNative.hpp"
#include "header/game.hpp"


int main() {
  AppNative native(640, 480, "hoge");
  native.setClearColor(Color::gray());

  Game game(&native);

  while (native.isOpen() && !native.isPushKey(GLFW_KEY_ESCAPE)) {
    native.clearWindowBuff();

    game.run();

    native.updateEvent();
  }
}
