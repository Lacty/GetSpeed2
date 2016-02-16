
#pragma once
#include "../sceneBase.hpp"
#include "../../Stage/stage.hpp"
#include "../../Airframe/airframe.hpp"


class Game : public SceneBase {
private:
  Font font;
  Stage stage;
  Airframe airframe;

  float angle;
  TwBar* twBar;

  void updateCamera();

public:
  Game(AppNative* app);
  ~Game();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};
