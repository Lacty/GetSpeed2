
#pragma once
#include <memory>

#include "../AppNative/appNative.hpp"


class SceneBase {
protected:
  AppNative* app;
  bool       isFinish;

  TwBar* twBar;

public:
  SceneBase(AppNative* app) :
  app(app),
  isFinish(false) {}

  virtual void update() = 0;
  virtual void draw()   = 0;
  virtual std::shared_ptr<SceneBase> nextScene(AppNative* app) = 0;

  bool shouldClose() { return isFinish; }
};
