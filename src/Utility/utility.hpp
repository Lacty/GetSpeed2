
#pragma once
#include <cmath>
#include <string>
#include <iostream>
#include "../Vector/vector.hpp"


float toRadians(float deg);

mat4f rotMatrix(const vec3f& vec);

mat4f transMatrix(const vec3f& vec);

double toSita(const vec2f& v1, const vec2f& v2);

vec3f getPointBezier(float t,
                     const vec3f& start,
                     const vec3f& v1,
                     const vec3f& v2,
                     const vec3f& end);


template<typename T>
inline void D_LOG(const T& src) {
  std::cout << src << std::endl;
}
