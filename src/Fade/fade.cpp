
#include "fade.hpp"
#include "../AppNative/appNative.hpp"


Fade::Fade(Type _type, float _speed) :
type(_type),
speed(_speed)
{
  alpha =  type == Type::In ?     1 :    0;
  speed *= type == Type::In ? -0.01 : 0.01;
}


void Fade::draw(AppNative* app) {
  // 1 3
  // 2 4
  GLfloat vtx[] = {
    -app->windowHalff().x(),  app->windowHalff().y(),
    -app->windowHalff().x(), -app->windowHalff().y(),
     app->windowHalff().x(),  app->windowSizef().y(),
     app->windowHalff().x(), -app->windowHalff().y()
  };
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  glColor4f(0.0f, 0.0f, 0.0f, alpha);   // gray
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDisableClientState(GL_VERTEX_ARRAY);
  
  glDisable(GL_BLEND);
  
  if (isFinish()) return;
  alpha += speed;
}

bool Fade::isFinish() {
  if (type == Type::In) {
    return alpha <= 0.0;
  }
  return alpha >= 1.0;
}