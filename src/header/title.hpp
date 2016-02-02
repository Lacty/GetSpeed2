
#pragma once
#include "sceneBase.hpp"


class Title : public SceneBase {
private:
  Font font;

public:
  Title(AppNative* app);

  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};
