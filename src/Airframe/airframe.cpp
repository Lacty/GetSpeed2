
#include "airframe.hpp"
#include "../MeshLoader/meshLoader.hpp"
#include "../LoadPath/loadPath.hpp"
#include <array>
#include <GLFW/glfw3.h>


Airframe::Airframe(Type _type, State _state) :
type(_type),
state(_state)
{
  std::array<std::string, 1> typeToText{ "Normal" };
  MeshLoader loader(loadAssets("airframe.json"), typeToText[(int)type]);
  mesh = loader.get();
}


void Airframe::accel() {}

void Airframe::handle(const float _angle) {}

void Airframe::update() {}

void Airframe::draw() {
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);

  // draw Mesh
  glVertexPointer(3, GL_FLOAT, 0, mesh.pVertex());
  glColorPointer(4, GL_FLOAT, 0, mesh.pColor());
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_TRIANGLES, 0, mesh.VertexNum());
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

  glDisable(GL_BLEND);

  // draw Wire
  glColor4i(0, 0, 0, 1);
  for(int i = 0; i < mesh.vertex.size(); i+=9) {
    std::cout << i << std::endl;
    glVertexPointer(3, GL_FLOAT, 0, mesh.pVertex(i));
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_LINE_LOOP, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

const vec3f& Airframe::getPos()     const { return pos; }
const vec3f& Airframe::getCenter()  const { return center; }
const vec3f& Airframe::getSide()    const { return side; }
const vec3f& Airframe::getForward() const { return forward; }

void Airframe::setPos(const vec3f& _pos)         { pos     = _pos; }
void Airframe::setCenter(const vec3f& _center)   { center  = _center; }
void Airframe::setSide(const vec3f& _side)       { side    = _side; }
void Airframe::setForward(const vec3f& _forward) { forward = _forward; }