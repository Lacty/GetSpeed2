
#pragma once
#include "../Vector/vector.hpp"


double toRadians(float deg);

Vec3f nearPosOnLine(const Vec3f& p,
                    const Vec3f& vA,
                    const Vec3f& vB);

template<typename T>
Vec2<T> pToVec2(const T* p) {
  assert((p != nullptr) && ((p + 1) != nullptr));
  return Vec2<T>(static_cast<T>(*p), static_cast<T>(*(p + 1)));
}

template<typename T>
Vec3<T> pToVec3(const T* p) {
  assert((p != nullptr) && ((p + 1) != nullptr) && ((p + 2) != nullptr));
  return Vec3<T>(static_cast<T>(*p), static_cast<T>(*(p + 1)), static_cast<T>(*(p + 2)));
}