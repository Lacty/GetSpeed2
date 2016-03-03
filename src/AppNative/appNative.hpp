
#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

#include "../Noncopyable/noncopyable.hpp"
#include "../Vector/vector.hpp"
#include "../Rect/rect.hpp"


class AppNative : public Noncopyable {
private:
  GLFWwindow* _gl_win;
  Recti       _window;

  GLFWwindow* createWindow(const Vec2i& size, const std::string& title);

public:
  AppNative() = delete;
  AppNative(const Vec2i& size,
            const std::string& title);

  bool isOpen();

  AppNative* begin();
  AppNative* end();
};