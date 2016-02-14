
#include "stage.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


Stage::Stage() {
  for(int i = -2; i < 20; i++) {
    mesh.pushBack(vec3f( 1, 0, -i), Color::white());
    mesh.pushBack(vec3f(-1, 0, -i), Color::white());
  }
}


void Stage::update() {}

void Stage::draw() {
  // Dequeはポインタがつながってないので
  // glに渡せるようにvectorに一時保存する
  std::vector<GLfloat> vtx(mesh.vertex.size());
  vtx.assign(mesh.vertex.begin(), mesh.vertex.end());
  std::vector<GLfloat> col(mesh.color.size());
  col.assign(mesh.color.begin(), mesh.color.end());

  // Mesh
  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glColorPointer(4, GL_FLOAT, 0, &col[0]);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh.VertexNum());
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);


  // Wire
  // 色を黒くする
  for(auto& it : col) { it -= 0.7f; }
  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glColorPointer(4, GL_FLOAT, 0, &col[0]);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glDrawArrays(GL_LINE_STRIP, 0, mesh.VertexNum());
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}