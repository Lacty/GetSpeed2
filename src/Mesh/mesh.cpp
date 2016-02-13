
#include "mesh.hpp"
#include <cassert>


const int Mesh::VertexNum() const {
  assert(!(vertex.size() % 3));
  return (int)vertex.size() / 3;
}

float* Mesh::pVertex(const unsigned int _index) {
  // 配列外にアクセスしたらエラー
  assert(_index < (int)vertex.size());
  return &vertex[_index];
}

float* Mesh::pColor(const unsigned int _index) {
  // 配列外にアクセスしたらエラー
  assert(_index < (int)vertex.size());
  return &color[_index];
}

vec3f& Mesh::Vertex(const unsigned int _index) {
  const unsigned int index = _index * 3;
  return vec3f(vertex[index],
               vertex[index + 1],
               vertex[index + 2]);
}

Color& Mesh::Color(const unsigned int _index) {
  return Color::blue();
}