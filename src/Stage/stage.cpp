
#include "stage.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


Stage::Stage() {
  for(int i = -2; i < 20; i++) {
    mesh.pushBack(vec3f( 1, 0, -i), Color::white());
    mesh.pushBack(vec3f(-1, 0, -i), Color::white());
  }
  updateData();
}


void Stage::updateData() {
  // gl‚É“n‚¹‚é‚æ‚¤‚Évector‚ÉˆêŽž•Û‘¶‚·‚é
  vtx.resize(mesh.vertex.size());
  vtx.assign(mesh.vertex.begin(), mesh.vertex.end());
  col.resize(mesh.color.size());
  col.assign(mesh.color.begin(), mesh.color.end());
}

void Stage::update() {
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
  // F‚ð•‚­‚·‚é
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