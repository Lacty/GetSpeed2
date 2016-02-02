
#pragma once
#include "appNative.hpp"
#include "sceneBase.hpp"


class Game : public SceneBase {
private:
public:
  Game(AppNative* app);
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};
