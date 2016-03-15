
#pragma once
#include "../Scene/sceneBase.hpp"
#include "../Audio/audio.hpp"
#include "../Audio/visualizer.hpp"


class Title : public SceneBase {
private:
  Font font_;
  Media media_;
  Visualizer visualizer_;

public:
  Title(AppNative* app);
  ~Title();
  
  void update();
  void draw();
  std::shared_ptr<SceneBase> nextScene(AppNative* app);
};