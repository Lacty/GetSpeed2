
#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Core>
#include <Eigen/Geometry>


template<typename T>
class Vec2 {
public:
  T x, y;

  Vec2() : x(0), y(0) {}
  Vec2(T x, T y) : x(x), y(y) {}
  Vec2(const Vec2<int>& src) : x(src.x), y(src.y) {}
  Vec2(const Vec2<float>& src) : x(src.x), y(src.y) {}
  Vec2(const Vec2<double>& src) : x(src.x), y(src.y) {}

  static Vec2<T> zero() { return Vec2<T>(0, 0); }
  static Vec2<T> xAxis() { return Vec2<T>(1, 0); }
  static Vec2<T> yAxis() { return Vec2<T>(0, 1); }

  Vec2<T>& operator+=(const Vec2<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  Vec2<T>& operator-=(const Vec2<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  Vec2<T>& operator*=(const Vec2<T>& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }
  Vec2<T>& operator/=(const Vec2<T>& rhs) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }
  Vec2<T>& operator*=(const T& rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
  }
  Vec2<T>& operator/=(const T& rhs) {
    x /= rhs;
    y /= rhs;
    return *this;
  }
  Vec2<T> operator*(const T& rhs) const {
    return Vec2<T>(x * rhs, y * rhs);
  }
  Vec2<T> operator/(const T& rhs) const {
    return Vec2<T>(x / rhs, y / rhs);
  }

  friend std::ostream& operator<<(std::ostream& os, const Vec2<T>& rhs) {
    os << "[" << rhs.x << "," << rhs.y << "]";
    return os;
  }
};


template<typename T>
class Vec3 {
public:
  T x, y, z;

  Vec3() : x(0), y(0), z(0) {}
  Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
  Vec3(const Vec3<int>& src) : x(src.x), y(src.y), z(src.z) {}
  Vec3(const Vec3<float>& src) : x(src.x), y(src.y), z(src.z) {}
  Vec3(const Vec3<double>& src) : x(src.x), y(src.y), z(src.z) {}
  Vec3(const Vec2<int>& src) : x(src.x), y(src.y), z(0) {}
  Vec3(const Vec2<float>& src) : x(src.x), y(src.y), z(0) {}
  Vec3(const Vec2<double>& src) : x(src.x), y(src.y), z(0) {}

  Vec2<T> xy() const { return Vec2<T>(x, y); }

  static Vec3<T> zero() { return Vec3<T>(0, 0, 0); }
  static Vec3<T> xAxis() { return Vec3<T>(1, 0, 0); }
  static Vec3<T> yAxis() { return Vec3<T>(0, 1, 0); }
  static Vec3<T> zAxis() { return Vec3<T>(0, 0, 1); }

  T sum() const { return x + y + z; }

  Vec3<T>& operator+=(const Vec3<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }
  Vec3<T>& operator-=(const Vec3<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }
  Vec3<T>& operator*=(const Vec3<T>& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }
  Vec3<T>& operator/=(const Vec3<T>& rhs) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }
  Vec3<T>& operator*=(const T& rhs) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
  }
  Vec3<T>& operator/=(const T& rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
  }
  Vec3<T> operator*(const T& rhs) const {
    return Vec3<T>(x * rhs, y * rhs);
  }
  Vec3<T> operator/(const T& rhs) const {
    return Vec3<T>(x / rhs, y / rhs);
  }

  friend std::ostream& operator<<(std::ostream& os, const Vec3<T>& rhs) {
    os << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "]";
    return os;
  }
};

typedef Vec2<int>    Vec2i;
typedef Vec2<float>  Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec3<int>    Vec3i;
typedef Vec3<float>  Vec3f;
typedef Vec3<double> Vec3d;