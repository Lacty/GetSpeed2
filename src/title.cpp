
#include "header/title.hpp"
#include "header/sceneMaker.hpp"


Title::Title(AppNative* app) :
SceneBase(app),
font("assets/rounded-l-mplus-1c-regular.ttf")
{
  font.setSize(50);
}


void Title::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
    D_LOG(isFinish);
  }
}

void Title::draw() {
  GLfloat vtx[] = {
    0.0f, 0.433f, 0.0f,
    -0.5f, -0.433f, 0.0f,
    0.5f, -0.433f, 0.0f
  };
  glPushMatrix();
    glVertexPointer(3, GL_FLOAT, 0, vtx);
    glTranslatef(0, 0, -10);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
  glPopMatrix();

  std::string str("hoge");
  font.draw(str, vec2f(0, 0));
  font.drawCenter(str, vec2f(100, 200));
}

std::shared_ptr<SceneBase> Title::nextScene(AppNative* app) {
  return sceneCreate<Game>(app);
}
