
#pragma once
#include "../Vector/vector.hpp"
#include "../Mesh/mesh.hpp"


class Stage {
private:
  Mesh mesh;

public:
  Stage();

  void update();
  void draw();
};