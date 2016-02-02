
#include "header/title.hpp"
#include "header/sceneMaker.hpp"


Title::Title(AppNative* app) :
SceneBase(app),
font("assets/rounded-l-mplus-1c-regular.ttf")
{
  if (font.Error()) {
    D_LOG("font did not loaded\n");
  }
  font.FaceSize(100);
}

void Title::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
    D_LOG(isFinish);
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

  font.Render("TITLE", 5, FTPoint(200.0f, 250.0f));
}

std::shared_ptr<SceneBase> Title::nextScene(AppNative* app) {
  return sceneCreate<Game>(app);
}
