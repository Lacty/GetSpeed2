
#include "stage.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


Stage::Stage() :
crCount(0) {
  for(int i = 0; i < 30; i++) {
    mesh.pushBack(vec3f(1, 0, -i), Color::white());
    mesh.pushBack(vec3f(-1, 0, -i), Color::white());
  }
  updateData();
}


void Stage::killPolyPassed(const int _index) {
  if(!(_index >= 12)) return;
  crCount += int((_index - 6)  / 3); // Á‚µ‚½’¸“_‚Ì”‚ğ•Û‘¶
  std::cout << crCount << std::endl;
  for(int i = 0; i < _index - 6; i++) {
    mesh.vertex.pop_front();
  }
}

void Stage::createStage() {
  
}

void Stage::updateData() {
  // gl‚É“n‚¹‚é‚æ‚¤‚Évector‚Éˆê•Û‘¶‚·‚é
  vtx.resize(mesh.vertex.size());
  vtx.assign(mesh.vertex.begin(), mesh.vertex.end());
  col.resize(mesh.color.size());
  col.assign(mesh.color.begin(), mesh.color.end());
}

void Stage::update(const int _index) {
  killPolyPassed(_index);
  createStage();
  updateData();
}

void Stage::draw() {
  // Mesh
  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glColorPointer(4, GL_FLOAT, 0, &col[0]);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh.VertexNum());
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

  // Wire
  // F‚ğ•‚­‚·‚é
  for(auto& it : col) { it -= 0.7f; }
  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glColorPointer(4, GL_FLOAT, 0, &col[0]);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glDrawArrays(GL_LINE_STRIP, 0, mesh.VertexNum());
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}


const std::vector<float>& Stage::getVtx() const {
  return vtx;
}

const std::vector<float>& Stage::getCol() const {
  return col;
}