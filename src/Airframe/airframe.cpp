
#include "airframe.hpp"
#include "../MeshLoader/meshLoader.hpp"
#include "../LoadPath/loadPath.hpp"
#include <array>
#include <GLFW/glfw3.h>


Airframe::Airframe() :
pos(0, 0, 0),
center(0, 0, -1),
up(0, 1, 0),
speedRate(0.2)
{
  forward = center - pos;
  side = forward.cross(up);
}

Airframe::Airframe(Type _type, State _state) :
Airframe()
{
  type = _type;
  state = _state;
  std::array<std::string, 1> typeToText{ "Normal" };
  MeshLoader loader(loadAssets("airframe.json"), typeToText[(int)type]);
  mesh = loader.get<std::vector<float>>();
}


void Airframe::evForward() {
  pos += forward * speedRate;
}

void Airframe::accel() {
  evForward();
}

void Airframe::handle(const float _rate) {
  pos += side * speedRate * _rate;
}

void Airframe::update() {
  forward = pos - center;
}

void Airframe::draw() {
  glPushMatrix();
  glTranslatef(pos.x(), pos.y(), pos.z());

  {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);

    // Mesh
    glVertexPointer(3, GL_FLOAT, 0, mesh.pVertex());
    glColorPointer(4, GL_FLOAT, 0, mesh.pColor());
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLES, 0, mesh.VertexNum());
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glDisable(GL_BLEND);

    // Wire
    glColor4i(0, 0, 0, 1);
    for(int i = 0; i < mesh.vertex.size(); i += 9) {
      glVertexPointer(3, GL_FLOAT, 0, mesh.pVertex(i));
      glEnableClientState(GL_VERTEX_ARRAY);
      glDrawArrays(GL_LINE_LOOP, 0, 3);
      glDisableClientState(GL_VERTEX_ARRAY);
    }
  }

  glPopMatrix();
}

const vec3f& Airframe::getPos()     const { return pos; }
const vec3f& Airframe::getCenter()  const { return center; }
const vec3f& Airframe::getSide()    const { return side; }
const vec3f& Airframe::getForward() const { return forward; }

void Airframe::setPos(const vec3f& _pos)         { pos     = _pos; }
void Airframe::setCenter(const vec3f& _center)   { center  = _center; }
void Airframe::setSide(const vec3f& _side)       { side    = _side; }
void Airframe::setForward(const vec3f& _forward) { forward = _forward; }