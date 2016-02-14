
#pragma once
#include <vector>
#include <deque>
#include "../Vector/vector.hpp"
#include "../Color/color.hpp"


template<typename T>
class Mesh {
public:
  Mesh() = default;
  T vertex;
  T color;

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

  vec3f& Vertex (const unsigned int _index = 0) {
    const unsigned int index = _index * 3;
    return vec3f(vertex[index],
                 vertex[index + 1],
                 vertex[index + 2]);
  }
  Color& Color  (const unsigned int _index = 0) {
    return Color::blue();
  }
};