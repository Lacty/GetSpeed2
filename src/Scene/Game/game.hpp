
#pragma once
#include "../sceneBase.hpp"


class Game : public SceneBase {
private:
  Font font;

public:
  Game(AppNative* app);
  ~Game();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};
