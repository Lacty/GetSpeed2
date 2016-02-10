
#pragma once


template<typename T>
class ColorT {
public:
  T r, g, b, a;

  ColorT() : r(0), g(0), b(0), a(0) {}
  ColorT(T r, T g, T b, T a) : r(r), g(g), b(b), a(a) {}
  ColorT(const ColorT<T>& src) : r(src.r), g(src.g), b(src.b), a(src.a) {}

  ColorT<T> operator+(const ColorT<T>& rhs) const { return ColorT<T>(r + rhs.r, g + rhs.g, b + rhs.b, a + rhs.a); }
  ColorT<T> operator-(const ColorT<T>& rhs) const { return ColorT<T>(r - rhs.r, g - rhs.g, b - rhs.b, a - rhs.a); }
  ColorT<T> operator*(const ColorT<T>& rhs) const { return ColorT<T>(r * rhs.r, g * rhs.g, b * rhs.b, a * rhs.a); }
  ColorT<T> operator/(const ColorT<T>& rhs) const { return ColorT<T>(r / rhs.r, g / rhs.g, b / rhs.b, a / rhs.a); }
  ColorT<T> operator+(T rhs) const { return ColorT<T>(r + rhs, g + rhs, b + rhs, a + rhs); }
  ColorT<T> operator-(T rhs) const { return ColorT<T>(r - rhs, g - rhs, b - rhs, a - rhs); }
  ColorT<T> operator*(T rhs) const { return ColorT<T>(r * rhs, g * rhs, b * rhs, a * rhs); }
  ColorT<T> operator/(T rhs) const { return ColorT<T>(r / rhs, g / rhs, b / rhs, a / rhs); }
  const ColorT<T>& operator+=(const ColorT<T>& rhs) { r += rhs.r; g += rhs.g; b += rhs.b; a += rhs.a; return *this; }
  const ColorT<T>& operator-=(const ColorT<T>& rhs) { r -= rhs.r; g -= rhs.g; b -= rhs.b; a -= rhs.a; return *this; }
  const ColorT<T>& operator*=(const ColorT<T>& rhs) { r *= rhs.r; g *= rhs.g; b *= rhs.b; a *= rhs.a; return *this; }
  const ColorT<T>& operator/=(const ColorT<T>& rhs) { r /= rhs.r; g /= rhs.g; b /= rhs.b; a /= rhs.a; return *this; }
  const ColorT<T>& operator+=(T rhs) { r += rhs; g += rhs; b += rhs; a += rhs; return *this; }
  const ColorT<T>& operator-=(T rhs) { r -= rhs; g -= rhs; b -= rhs; a -= rhs; return *this; }
  const ColorT<T>& operator*=(T rhs) { r *= rhs; g *= rhs; b *= rhs; a *= rhs; return *this; }
  const ColorT<T>& operator/=(T rhs) { r /= rhs; g /= rhs; b /= rhs; a /= rhs; return *this; }

  inline static ColorT<T> white()  { return ColorT<T>(1, 1, 1, 1); }
  inline static ColorT<T> red()    { return ColorT<T>(1, 0, 0, 1); }
  inline static ColorT<T> green()  { return ColorT<T>(0, 1, 0, 1); }
  inline static ColorT<T> blue()   { return ColorT<T>(0, 0, 1, 1); }
  inline static ColorT<T> orange() { return ColorT<T>(1.0f, 0.6f, 0.0f, 1.0f); }
  inline static ColorT<T> gray()   { return ColorT<T>(0.4f, 0.4f, 0.4f, 1.0f); }
};

typedef ColorT<float> Color;
