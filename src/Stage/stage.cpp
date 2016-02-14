
#include "stage.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


Stage::Stage() {
  mesh.pushBack(vec3f(1, 0, 0), Color::white());
  mesh.pushBack(vec3f(-1, 0, 0), Color::white());
  mesh.pushBack(vec3f(1, 0, -1), Color::white());
  mesh.pushBack(vec3f(-1, 0, -1), Color::white());
  mesh.pushBack(vec3f(-1, 0, -1), Color::white());
  mesh.pushBack(vec3f(-1, 0, -1), Color::white());
}


void Stage::update() {}

void Stage::draw() {
  std::vector<GLfloat> vtx(mesh.vertex.size());
  vtx.assign(mesh.vertex.begin(), mesh.vertex.end());
  std::vector<GLfloat> col(mesh.color.size());
  col.assign(mesh.color.begin(), mesh.color.end());

  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glColorPointer(4, GL_FLOAT, 0, &col[0]);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}