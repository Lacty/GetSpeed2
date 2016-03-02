
#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

#include "../Noncopyable/noncopyable.hpp"
#include "../Vector/vector.hpp"
#include "../Rect/rect.hpp"


class AppNative : public Noncopyable {
private:
  GLFWwindow* _window;

public:
  AppNative(const Vec2i& size,
            const std::string& title);
};