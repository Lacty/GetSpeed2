
#pragma once
#include <memory>
#include "appNative.hpp"
#include "sceneBase.hpp"

#include "sceneMaker.hpp"


class Game {
private:
  AppNative* app;
  std::shared_ptr<SceneBase> scene;
  
  void update();
  void draw();

public:
  Game(AppNative* app);
  
  void run();
};
