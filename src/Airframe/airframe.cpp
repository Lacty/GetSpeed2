
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

void Airframe::handle(float _angle) {}

void Airframe::update() {}

void Airframe::draw() {
  glVertexPointer(3, GL_FLOAT, 0, mesh.pVertex());
  glColorPointer(4, GL_FLOAT, 0, mesh.pColor());
  glEnableClientState(GL_COLOR_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}