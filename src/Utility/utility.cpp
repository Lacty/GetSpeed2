
#include "utility.hpp"


float toRadians(float deg) {
  return float(deg * M_PI) / 180.0f;
}

mat4f rotMatrix(const vec3f& vec) {
  float x = toRadians(vec.x());
  float y = toRadians(vec.y());
  float z = toRadians(vec.z());

  Eigen::Matrix4f matX;
  matX << 1, 0, 0, 0,
    0, std::cos(x), -std::sin(x), 0,
    0, std::sin(x), std::cos(x), 0,
    0, 0, 0, 1;

  Eigen::Matrix4f matY;
  matY << std::cos(y), 0, std::sin(y), 0,
    0, 1, 0, 0,
    -std::sin(y), 0, std::cos(y), 0,
    0, 0, 0, 1;

  Eigen::Matrix4f matZ;
  matZ << std::cos(z), -std::sin(y), 0, 0,
    std::sin(z), std::cos(y), 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1;

  return matX * matY * matZ;
}

mat4f transMatrix(const vec3f& vec) {
  float x = vec.x();
  float y = vec.y();
  float z = vec.z();

  Eigen::Matrix4f m;
  m << 1, 0, 0, x,
    0, 1, 0, y,
    0, 0, 1, z,
    0, 0, 0, 1;

  return m;
}

double toSita(const vec2f& v1, const vec2f& v2) {
  double cosSita = v1.dot(v2) / (v1.norm() * v2.norm());
  double sita = acos(cosSita);
  sita = sita * 180.0 / M_PI;
  return sita;
}

vec3f getPointBezier(float t,
                     const vec3f& start,
                     const vec3f& v1,
                     const vec3f& v2,
                     const vec3f& end)
{
  float tp = 1 - t;
  vec3f pos(0, 0, 0);
  pos.x() = t*t*t*end.x() + 3 * t*t*tp*v2.x() + 3 * t*tp*tp*v1.x() + tp*tp*tp*start.x();
  pos.y() = t*t*t*end.y() + 3 * t*t*tp*v2.y() + 3 * t*tp*tp*v1.y() + tp*tp*tp*start.y();
  pos.z() = t*t*t*end.z() + 3 * t*t*tp*v2.z() + 3 * t*tp*tp*v1.z() + tp*tp*tp*start.z();
  return pos;
}

vec3f getPointCatmullRom(float t,
                         const vec3f& p0,
                         const vec3f& p1,
                         const vec3f& p2,
                         const vec3f& p3)
{
  vec3f pos;
  pos.x() = 0.5f * ((2 * p1.x()) +
             (-p0.x() + p2.x()) * t +
             (2 * p0.x() - 5 * p1.x() + 4 * p2.x() - p3.x()) * (t*t) +
             (-p0.x() + 3 * p1.x() - 3 * p2.x() + p3.x()) * (t*t*t));
  pos.y() = 0.5f * ((2 * p1.y()) +
             (-p0.y() + p2.y()) * t +
             (2 * p0.y() - 5 * p1.y() + 4 * p2.y() - p3.y()) * (t*t) +
             (-p0.y() + 3 * p1.y() - 3 * p2.y() + p3.y()) * (t*t*t));
  pos.z() = 0.5f * ((2 * p1.z()) +
             (-p0.z() + p2.z()) * t +
             (2 * p0.z() - 5 * p1.z() + 4 * p2.z() - p3.z()) * (t*t) +
             (-p0.z() + 3 * p1.z() - 3 * p2.z() + p3.z()) * (t*t*t));
  return pos;
}

vec3f ReturnCatmullRom(float t, vec3f p0, vec3f p1, vec3f p2, vec3f p3) {
  vec3f a = 0.5f * (2.f * p1);
  vec3f b = 0.5f * (p2 - p0);
  vec3f c = 0.5f * (2.f * p0 - 5.f * p1 + 4.f * p2 - p3);
  vec3f d = 0.5f * (-p0 + 3.f * p1 - 3.f * p2 + p3);

  vec3f pos = a + (b * t) + (c * t * t) + (d * t * t * t);

  return pos;
}

vec3f nearPosOnLine(const vec3f& _p,
                    const vec3f& _vA,
                    const vec3f& _vB)
{
  vec3f AB, AP;
  AB = _vB - _vA;
  AP = _p - _vA;

  AB.normalize();
  
  // A‚©‚çNearPos‚Ü‚Å‚Ì‹——£
  double distAX = AB.dot(AP);

  // NearPos
  vec3f ret;
  ret = _vA + (AB * distAX);

  return ret;
}

vec3f arrayToVec3f(const float* _v) {
  return vec3f(*_v, *(_v + 1), *(_v + 2));
}

void V2_LOG(const vec2f& src) {
  std::cout << "[" << src.x() << "," << src.y() << "]" << std::endl;
}

void V3_LOG(const vec3f& src) {
  std::cout << "[" << src.x() << "," << src.y() << "," << src.z() << "]" << std::endl;
}

void enableRandom() {
  std::random_device rand;
  Hidden::mt = std::mt19937_64(rand());
}

int randFirstLast(const int _first, const int _last) {
  std::uniform_int_distribution<> rand(_first, _last);
  return rand(Hidden::mt);
}

int randZeroLast(const int _last) {
  std::uniform_int_distribution<> rand(0, _last);
  return rand(Hidden::mt);
}