
#pragma once
#include "../Vector/vector.hpp"
#include "../Mesh/mesh.hpp"


class Stage {
private:
  Mesh<std::deque<float>> mesh;
  std::vector<float> vtx;
  std::vector<float> col;

public:
  Stage();

  void update();
  void draw();
};