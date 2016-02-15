
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

vec3f getPointCatmullRom(float t,
                         const vec3f& p1,
                         const vec3f& p2,
                         const vec3f& p3,
                         const vec3f& p4);

vec3f ReturnCatmullRom(float t, vec3f p0, vec3f p1, vec3f p2, vec3f p3);

vec3f nearPosOnLine(const vec3f& _p,
                    const vec3f& _vA,
                    const vec3f& _vB);

vec3f arrayToVec3f(const float* _v);

template<typename T>
inline void D_LOG(const T& src) {
  std::cout << src << std::endl;
}

void V2_LOG(const vec2f& src);
void V3_LOG(const vec3f& src);