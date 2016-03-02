
#pragma once
#include "../Vector/vector.hpp"


template<typename T>
class Rect2d {
public:
  Vec2<T> pos;
  Vec2<T> size;

  Rect2d() = default;
  Rect2d(const T& width, const T& height) : pos(width * 0.5f, height * 0.5f), size(width, height) {}
  Rect2d(const Vec2<T>& size) : pos(size.x * 0.5f, size.y * 0.5f), size(size) {}
  Rect2d(const Vec2<T>& pos, const Vec2<T>& size) : pos(pos), size(size) {}

  T left()   const { return pos.x - size.x * 0.5f; }
  T right()  const { return pos.x + size.x * 0.5f; }
  T top()    const { return pos.y + size.y * 0.5f; }
  T bottom() const { return pos.y - size.y * 0.5f; }

  Vec2<T> leftTop()     const { return Vec2<T>(left(), top()); }
  Vec2<T> leftBottom()  const { return Vec2<T>(left(), bottom()); }
  Vec2<T> rightTop()    const { return Vec2<T>(right(), top()); }
  Vec2<T> rightBottom() const { return Vec2<T>(right(), bottom()); }

  friend std::ostream& operator<<(std::ostream& os, const Rect2d<T>& rhs) {
    os << rhs.pos << rhs.size;
    return os;
  }
};

typedef Rect2d<int>    Recti;
typedef Rect2d<float>  Rectf;
typedef Rect2d<double> Rectd;