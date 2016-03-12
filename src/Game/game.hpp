
#pragma once
#include "../Scene/sceneBase.hpp"


class Game : public SceneBase {
private:
public:
  Game(AppNative* app);
  ~Game();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};