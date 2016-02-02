
#pragma once
#include "sceneBase.hpp"

#include <FTGL/ftgl.h>


class Title : public SceneBase {
private:
  FTPixmapFont font;

public:
  Title(AppNative* app);

  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};
