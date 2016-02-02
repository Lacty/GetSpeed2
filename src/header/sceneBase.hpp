
#pragma once
#include <GLFW/glfw3.h>
#include <memory>
#include "appNative.hpp"
#include "utility.hpp"


class SceneBase {
protected:
  AppNative* app;
  bool       isFinish;

public:
  SceneBase(AppNative* app) : app(app) {}

  virtual void update() = 0;
  virtual void draw()   = 0;
  virtual std::shared_ptr<SceneBase> nextScene(AppNative* app) = 0;

  bool shouldClose() { return isFinish; }
};
