
#pragma once
#include "../sceneBase.hpp"


class Title : public SceneBase {
private:
  Font font;

  vec3f start;
  vec3f v1;
  vec3f v2;
  vec3f end;
  float t;
  
  TwBar* twBar;

public:
  Title(AppNative* app);
  ~Title();

  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};
