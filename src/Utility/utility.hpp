
#pragma once
#include <type_traits>
#include "../Vector/vector.hpp"


double toRadians(float deg);

Vec3f nearPosOnLine(const Vec3f& p,
                    const Vec3f& vA,
                    const Vec3f& vB);

template<typename T, typename Itr>
Vec2<T> toVec2(Itr begin, Itr end, int idx) {
  return Vec2<T>(static_cast<T>(*(begin + idx)), static_cast<T>(*(begin + (idx + 1))));
}

template<typename T, typename Itr>
Vec2<T> toVec2(Itr p, int idx) {
  return Vec2<T>(static_cast<T>(*(p + idx)), static_cast<T>(*(p + (idx + 1))));
}

template<typename T, typename Itr>
Vec3<T> toVec3(Itr begin, Itr end, int idx) {
  return Vec3<T>(static_cast<T>(*(begin + idx)), static_cast<T>(*(begin + (idx + 1))), static_cast<T>(*(begin + (idx + 2))));
}

template<typename T, typename Itr>
Vec3<T> toVec3(Itr p, int idx) {
  return Vec3<T>(static_cast<T>(*(p + idx)), static_cast<T>(*(p + (idx + 1))), static_cast<T>(*(p + (idx + 2))));
}