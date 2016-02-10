
#pragma once
#include "vector.hpp"
#include <Pico/picojson.h>


class Airframe {
private:
  vec3f pos;
  vec3f center;
  vec3f up;
  vec3f side;
  vec3f forward;

  float speedRate;

public:
  Airframe(const std::string& path);

  void accel();
  void handle(float _rate);

  void update();
  void draw();
};
