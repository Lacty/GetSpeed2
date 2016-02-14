
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
  
  Mesh<std::vector<float>> mesh;

  vec3f pos;
  vec3f center;
  vec3f up;
  vec3f side;
  vec3f forward;

  float speedRate;

public:
  Airframe();
  Airframe(Type _type, State _state);

  void accel();
  void handle(const float _rate);

  void update();
  void draw();

  const vec3f& getPos() const;
  const vec3f& getCenter() const;
  const vec3f& getSide() const;
  const vec3f& getForward() const;

  void setPos(const vec3f& _pos);
  void setCenter(const vec3f& _center);
  void setSide(const vec3f& _side);
  void setForward(const vec3f& _forward);
};
