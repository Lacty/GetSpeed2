
#include "sceneBase.hpp"


void SceneBase::drawFade() {
  fade_.draw();
}

bool SceneBase::shouldClose() {
  return is_finish_ && fade_.isFinish();
}