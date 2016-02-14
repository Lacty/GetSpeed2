
#pragma once
#include "../Vector/vector.hpp"
#include "../Mesh/mesh.hpp"


class Stage {
private:
  Mesh<std::deque<float>> mesh;

public:
  Stage();

  void update();
  void draw();
};