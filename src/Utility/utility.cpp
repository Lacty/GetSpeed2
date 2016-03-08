
#include "utility.hpp"


float toRadians(float deg) {
  return float(deg * M_PI) / 180.0f;
}

Vec3f nearPosOnLine(const Vec3f& p,
                    const Vec3f& vA,
                    const Vec3f& vB)
{
  Vec3f AB, AP;
  AB = vB - vA;
  AP = p - vA;

  AB.normalize();

  // A‚©‚çNearPos‚Ü‚Å‚Ì‹——£
  double distAX = AB.dot(AP);

  // NearPos
  Vec3f ret;
  ret = vA + (AB * distAX);

  return ret;
}