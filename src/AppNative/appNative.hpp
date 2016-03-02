
#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

#include "../Noncopyable/noncopyable.hpp"


class AppNative : public Noncopyable {
private:
  GLFWwindow* _window;

public:
  AppNative(const int width,
            const int height,
            const std::string& title);
};