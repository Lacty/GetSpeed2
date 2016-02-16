
#include "title.hpp"
#include "../sceneMaker.hpp"


Title::Title(AppNative* app) :
SceneBase(app),
font(loadAssets("rounded-l-mplus-1c-regular.ttf")),
start(-10, 0, 0),
v1(-5, 0, 0),
v2(5, 0, 0),
end(10, 10, 0),
t(0.0)
{
  std::cout << "start title" << std::endl;

  //twBar = TwNewBar("title");
  //TwAddVarRW(twBar, "t", TW_TYPE_FLOAT, &t, "min=0 max=1");
  
  app->startFade(Fade::Type::In);
}

Title::~Title() {
  TwDeleteBar(twBar);
  
  std::cout << "end title" << std::endl;
}


void Title::update() {
  if (app->isPushKey(GLFW_KEY_A)) {
    isFinish = true;
    app->startFade(Fade::Type::Out);
  }
  if (app->isPressKey(GLFW_KEY_T)) {
    if (t >= 1) t = 1;
    t += 0.01f;
  }
  font.setSize(50.0f * app->getWindowScale());
}

void Title::draw() {
  std::string str("- GetSpeed2 -");
  font.drawCenter(str, app->windowHalff());

  glPushMatrix();
    glTranslatef(0, 0, -10);

    vec3f p = CRSpline::Eq(t, start, v1, v2, end);

    glTranslatef(p.x() * 0.4f, p.y() * 0.4f, p.z() * 0.4f);
    GLfloat vtx[] = {
      0.0f, 0.433f, 0.0f,
      -0.5f, -0.433f, 0.0f,
      0.5f, -0.433f, 0.0f
    };
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertexPointer(3, GL_FLOAT, 0, vtx);
    glEnableClientState(GL_VERTEX_ARRAY);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
  glPopMatrix();
}

std::shared_ptr<SceneBase> Title::nextScene(AppNative* app) {
  return sceneCreate<Game>(app);
}
