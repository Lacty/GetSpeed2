
#include "airframe.hpp"
#include "../MeshLoader/meshLoader.hpp"
#include "../LoadPath/loadPath.hpp"
#include "../Utility/utility.hpp"
#include "../Graphic/graphic.hpp"
#include <array>
#include <GLFW/glfw3.h>


Airframe::Airframe() :
pos(0, 0, 0),
center(0, 0, -1),
up(0, 1, 0),
speedRate(0.01),
controlPointNum(10)
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


void Airframe::evControlPoint(const std::vector<float>& _vtx) {
  // TODO: 機体に一番近いポリゴンの頂点を求める
  int index = 12;

  // 配列のメモリ再確保(controlPoint分)
  nearOnLine.clear();
  nearOnLine.resize(controlPointNum);

  // 機体に一番近い線へ垂線を伸ばした時の交点を求める
  nearOnLine[0] = nearPosOnLine(pos, arrayToVec3f(&_vtx[index]), arrayToVec3f(&_vtx[index + 3]));
  float percentAN = vec3f(arrayToVec3f(&_vtx[index + 3]) - arrayToVec3f(&_vtx[index])).norm() / vec3f(nearOnLine[0] - arrayToVec3f(&_vtx[index])).norm();
  
  // 制御点を求める(頂点につき3なので次の偶数の頂点は6の倍数で求める
  for(int i = 1; i < controlPointNum; i++) {
    nearOnLine[i] = evNextOnLine(index + 6 * i, percentAN, _vtx);
  }

  // center
  center = nearOnLine[1];

  // side
  side = vec3f(arrayToVec3f(&_vtx[index]) - arrayToVec3f(&_vtx[index + 3])).normalized();
}

void Airframe::evForward() {
  forward = center - pos;
  forward.normalize();
}

vec3f Airframe::evNextOnLine(const int _index,
                             const float _percent,
                             const std::vector<float>& _vtx)
{
  vec3f distLine = arrayToVec3f(&_vtx[_index + 3]) - arrayToVec3f(&_vtx[_index]);
  vec3f distNear = distLine / _percent;
  return arrayToVec3f(&_vtx[_index]) + distNear;
}


void Airframe::drawUI() {
  // 機体とステージのLineの一番近い点を描画
  for(const auto& it : nearOnLine) {
    drawRect(it, vec2f(0.1f, 0.1f), Color::red());
  }
}

void Airframe::accel() {

}

void Airframe::handle(const float _rate) {
  pos += side * speedRate * _rate;
}

void Airframe::update(const std::vector<float>& _vtx) {
  evControlPoint(_vtx);
  evForward();
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

  drawUI();
}

const vec3f& Airframe::getPos()     const { return pos; }
const vec3f& Airframe::getCenter()  const { return center; }
const vec3f& Airframe::getSide()    const { return side; }
const vec3f& Airframe::getForward() const { return forward; }

void Airframe::setPos(const vec3f& _pos)         { pos     = _pos; }
void Airframe::setCenter(const vec3f& _center)   { center  = _center; }
void Airframe::setSide(const vec3f& _side)       { side    = _side; }
void Airframe::setForward(const vec3f& _forward) { forward = _forward; }