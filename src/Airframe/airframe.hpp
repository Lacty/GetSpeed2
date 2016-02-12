
#pragma once
#include "../Vector/vector.hpp"
#include "../Mesh/mesh.hpp"


class Airframe {
public:
  enum class Type { Normal };
  enum class State { Ready, Active, Dead };

private:
  Type type;
  State state;

  Mesh mesh;

  vec3f pos;
  vec3f center;
  vec3f up;
  vec3f side;
  vec3f forward;

  float speedRate;

public:
  Airframe() = default;
  Airframe(Type _type, State _state);

  void accel();
  void handle(float _angle);

  void update();
  void draw();
};
