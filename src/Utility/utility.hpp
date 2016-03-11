
#pragma once
#include <type_traits>
#include "../Vector/vector.hpp"


double toRadians(float deg);

Vec3f nearPosOnLine(const Vec3f& p,
                    const Vec3f& vA,
                    const Vec3f& vB);

// コンテナ用
template<typename T, typename Itr>
Vec2<T> toVec2(Itr begin, Itr end, int idx) {
  assert(((begin + idx) != end) && ((begin + (idx + 1)) != end));
  return Vec2<T>(static_cast<T>(*(begin + idx)), static_cast<T>(*(begin + (idx + 1))));
}

// 普通の配列用
template<typename T, typename Itr>
Vec2<T> toVec2(Itr p, int idx) {
  assert(((p + idx) != nullptr) && ((p + (idx + 1)) != nullptr));
  return Vec2<T>(static_cast<T>(*(p + idx)), static_cast<T>(*(p + (idx + 1))));
}

template<typename T, typename Itr>
Vec3<T> toVec3(Itr begin, Itr end, int idx) {
  assert(((begin + idx) != end) && ((begin + (idx + 1)) != end), ((begin + (idx + 2)) != nullptr));
  return Vec3<T>(static_cast<T>(*(begin + idx)), static_cast<T>(*(begin + (idx + 1))), static_cast<T>(*(begin + (idx + 2))));
}

template<typename T, typename Itr>
Vec3<T> toVec3(Itr p, int idx) {
  assert(((p + idx) != nullptr) && ((p + (idx + 1)) != nullptr) && ((p + (idx + 2)) != nullptr));
  return Vec3<T>(static_cast<T>(*(p + idx)), static_cast<T>(*(p + (idx + 1))), static_cast<T>(*(p + (idx + 2))));
}