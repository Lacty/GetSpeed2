
#include "title.hpp"
#include "../sceneMaker.hpp"


Title::Title(AppNative* app) :
SceneBase(app),
t(0.0),
start(-5, 0, 0),
v1(-2, 3, 0),
v2(1, -4, 0),
end(5, 0, 0),
font(loadAssets("rounded-l-mplus-1c-regular.ttf"))
{
  font.setSize(50);

  twBar = TwNewBar("title");
  TwAddVarRW(twBar, "t", TW_TYPE_FLOAT, &t, "min=0 max=1");
}

Title::~Title() {
  TwDeleteBar(twBar);
}


void Title::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
  }
  if (app->isPressKey(GLFW_KEY_T)) {
    if (t >= 1) t = 1;
    t += 0.01f;
  }
}

void Title::draw() {
  std::string str("- Title -");
  font.drawCenter(str, vec2f(app->windowSize().x() * 0.5f,
                             app->windowSize().y() * 0.5f));

  std::string str_fps;
  str_fps = std::to_string(app->getFps());
  font.drawCenter(str_fps, vec2f(app->windowSize().x() * 0.5f,
                                 app->windowSize().y() * 0.2f));

  glPushMatrix();
    glTranslatef(0, 0, -10);

    vec3f p = getPointBezier(t, start, v1, v2, end);
    glTranslatef(p.x() * 0.4f, p.y() * 0.4f, p.z() * 0.4f);
    GLfloat vtx[] = {
      0.0f, 0.433f, 0.0f,
      -0.5f, -0.433f, 0.0f,
      0.5f, -0.433f, 0.0f
    };
    glVertexPointer(3, GL_FLOAT, 0, vtx);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
  glPopMatrix();
}

std::shared_ptr<SceneBase> Title::nextScene(AppNative* app) {
  return sceneCreate<Game>(app);
}