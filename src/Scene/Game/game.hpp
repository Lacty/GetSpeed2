
#pragma once
#include "../sceneBase.hpp"
#include "../../Airframe/airframe.hpp"


class Game : public SceneBase {
private:
  Font font;
  Airframe airframe;

public:
  Game(AppNative* app);
  ~Game();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};
