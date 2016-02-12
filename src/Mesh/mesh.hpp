
#pragma once
#include <vector>
#include "../Vector/vector.hpp"
#include "../Color/color.hpp"


class Mesh {
public:
  Mesh() = default;
  std::vector<float> vertex;
  std::vector<float> color;

  float* pVertex(const unsigned int _index = 0);
  float* pColor (const unsigned int _index = 0);
  vec3f& Vertex (const unsigned int _index = 0);
  Color& Color  (const unsigned int _index = 0);
};