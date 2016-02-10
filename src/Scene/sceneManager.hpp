
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"
#include "../Scene/sceneBase.hpp"
#include "sceneMaker.hpp"


class SceneManager {
private:
  AppNative* app;
  std::shared_ptr<SceneBase> scene;
  
  void update();
  void draw();

public:
  SceneManager(AppNative* app);
  
  void run();
};
