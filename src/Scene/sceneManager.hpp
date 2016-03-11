
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"
#include "../Scene/sceneBase.hpp"
#include "sceneMaker.hpp"


class SceneManager {
private:
  AppNative* app_;
  std::shared_ptr<SceneBase> scene_;

public:
  SceneManager(AppNative* app);

  void update();
  void draw();
};