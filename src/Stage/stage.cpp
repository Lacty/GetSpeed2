
#include "stage.hpp"
#include "../Utility/utility.hpp"
#include <GLFW/glfw3.h>
#include <iostream>


Stage::Stage() :
width(3),
depth(2),
createCount(0),
shouldCreateCount(0)
{
  for(int i = -4; i < 20; i++) {
    mesh.pushBack(vec3f( width * 0.5, 0, -i * depth), Color::white());
    mesh.pushBack(vec3f(-width * 0.5, 0, -i * depth), Color::white());
  }
  updateData();

  type = Type::Right;
  createCount = 20;
}


void Stage::killPolyPassed(const int _index) {
  if(!(_index >= 15)) return;
  shouldCreateCount += int((_index - 6) / 3); // Á‚µ‚½’¸“_‚Ì”‚ğ•Û‘¶
  for(int i = 0; i < _index - 6; i++) {
    mesh.vertex.pop_front();
    mesh.color.pop_front();
  }
}

void Stage::decideType() {
  if(createCount) return;
  type = Type::Straight;
  createCount = 100;
}

void Stage::createStage() {
  if(!shouldCreateCount) return;

  // Forward Side‚ğ‹‚ß‚é
  evForwardAndSide();

  switch(type) {
    case Type::Straight:
    createStraight(); break;
    case Type::Right:
    createRight(); break;
  }
}

void Stage::createStraight() {
  mesh.pushBack(vec3f(mesh.vertex[mesh.vertex.size() - 6],
                      mesh.vertex[mesh.vertex.size() - 5],
                      mesh.vertex[mesh.vertex.size() - 4])
                + forward,
                Color::white());
  mesh.pushBack(vec3f(mesh.vertex[mesh.vertex.size() - 3],
                      mesh.vertex[mesh.vertex.size() - 2],
                      mesh.vertex[mesh.vertex.size() - 1])
                + side,
                Color::white());
  shouldCreateCount -= 2;
  createCount -= 2;
}

void Stage::createRight() {
  Eigen::Quaternionf quat;
  quat = Eigen::AngleAxisf(M_PI * -0.02f, up);
  forward = quat * forward;
  side    = quat * side;
  mesh.pushBack(vec3f(mesh.vertex[mesh.vertex.size() - 6],
                mesh.vertex[mesh.vertex.size() - 5],
                mesh.vertex[mesh.vertex.size() - 4])
                + forward,
                Color::white());
  mesh.pushBack(vec3f(mesh.vertex[mesh.vertex.size() - 3],
                mesh.vertex[mesh.vertex.size() - 2],
                mesh.vertex[mesh.vertex.size() - 1])
                + side,
                Color::white());
  shouldCreateCount -= 2;
  createCount -= 2;
}

void Stage::evForwardAndSide() {
  forward = vec3f(mesh.vertex[mesh.vertex.size() - 6],
                  mesh.vertex[mesh.vertex.size() - 5],
                  mesh.vertex[mesh.vertex.size() - 4])
    - vec3f(mesh.vertex[mesh.vertex.size() - 12],
            mesh.vertex[mesh.vertex.size() - 11],
            mesh.vertex[mesh.vertex.size() - 10]);
  side = vec3f(mesh.vertex[mesh.vertex.size() - 3],
               mesh.vertex[mesh.vertex.size() - 2],
               mesh.vertex[mesh.vertex.size() - 1])
    - vec3f(mesh.vertex[mesh.vertex.size() - 6],
            mesh.vertex[mesh.vertex.size() - 5],
            mesh.vertex[mesh.vertex.size() - 4]);
  forward.normalize();
  forward *= depth;
  side.normalize();
  side *= width;
  up = forward.cross(side).normalized();
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
  decideType();
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