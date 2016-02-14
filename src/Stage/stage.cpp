
#include "stage.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


Stage::Stage() {
  mesh.pushBack(vec3f(1, 0, 0), Color::white());
  mesh.pushBack(vec3f(-1, 0, 0), Color::white());
  mesh.pushBack(vec3f(1, 0, -1), Color::white());
  mesh.pushBack(vec3f(-1, 0, -1), Color::white());
  for(auto it : mesh.vertex) {
    std::cout << it << std::endl;
  }
  std::cout << mesh.VertexNum() << std::endl;
}


void Stage::update() {}

void Stage::draw() {
  glVertexPointer(3, GL_FLOAT, 0, mesh.pVertex());
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDisableClientState(GL_VERTEX_ARRAY);
}