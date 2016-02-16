
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"
#include "../Scene/sceneBase.hpp"
#include "sceneMaker.hpp"


class SceneManager {
private:
  AppNative* app;
  std::shared_ptr<SceneBase> scene;

public:
  SceneManager(AppNative* app);
  
  void update();
  void draw();
};
