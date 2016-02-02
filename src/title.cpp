
#include "header/title.hpp"
#include "header/sceneMaker.hpp"
#include <iostream>

#include <GLFW/glfw3.h>


Title::Title(AppNative* app) :
SceneBase(app) {}


void Title::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
  }
}

void Title::draw() {
  GLfloat vtx[] = {
    0.0, 0.0
  };
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  glPointSize(20);
  glTranslatef(0, 0, -10);
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_POINTS, 0, 1);
  glDisableClientState(GL_VERTEX_ARRAY);
}

std::shared_ptr<SceneBase> Title::nextScene(AppNative* app) {
  return sceneCreate<Game>(app);
}
