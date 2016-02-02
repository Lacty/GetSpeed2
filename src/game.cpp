
#include "header/game.hpp"
#include "header/sceneMaker.hpp"


Game::Game(AppNative* app) :
SceneBase(app) {}

void Game::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
  }
}

void Game::draw() {
  GLfloat vtx[] = {
    0.0, 0.0
  };
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  glPointSize(20);
  glTranslatef(0, 0, -10);
  glColor4f(1.0f, 0.f, 0.f, 1.0f);

  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_POINTS, 0, 1);
  glDisableClientState(GL_VERTEX_ARRAY);
}

std::shared_ptr<SceneBase> Game::nextScene(AppNative* app) {
  return sceneCreate<Title>(app);
}