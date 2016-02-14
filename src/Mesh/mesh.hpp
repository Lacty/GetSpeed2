
#pragma once
#include <vector>
#include "../Vector/vector.hpp"
#include "../Color/color.hpp"


class Mesh {
public:
  Mesh() = default;
  std::vector<float> vertex;
  std::vector<float> color;

  const int VertexNum() const {
    assert(!(vertex.size() % 3));
    return (int)vertex.size() / 3;
  }

  float* pVertex(const unsigned int _index = 0) {
    // 配列外にアクセスしたらエラー
    assert(_index < (int)vertex.size());
    return &vertex[_index];
  }

  float* pColor (const unsigned int _index = 0) {
    // 配列外にアクセスしたらエラー
    assert(_index < (int)vertex.size());
    return &color[_index];
  }

  vec3f& getVertex (const unsigned int _index = 0) {
    const unsigned int index = _index * 3;
    return vec3f(vertex[index],
                 vertex[index + 1],
                 vertex[index + 2]);
  }
  Color& getColor (const unsigned int _index = 0) {
    const unsigned int index = _index * 4;
    return Color(color[index],
                 color[index + 1],
                 color[index + 2],
                 color[index + 3]);
  }

  void pushBack(const vec3f& _v, const Color& _c) {
    vertex.push_back(_v.x());
    vertex.push_back(_v.y());
    vertex.push_back(_v.z());
    color.push_back(_c.r);
    color.push_back(_c.g);
    color.push_back(_c.b);
    color.push_back(_c.a);
  }
};