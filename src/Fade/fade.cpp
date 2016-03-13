
#include "fade.hpp"
#include "../AppNative/appNative.hpp"


Fade::Fade(Type type, float speed) :
  type_(type),
  speed_(speed)
{
  alpha_  = type == Type::In ?  1.00f : 0.00f;
  speed_ *= type == Type::In ? -0.01f : 0.01f;
}


void Fade::draw() {
  drawRect(Vec3f::zero(), Vec2f(2, 2), ColorA(0, 0, 0, alpha_));

  if (isFinish()) return;
  alpha_ += speed_;
}

bool Fade::isFinish() {
  if (type_ == Type::In) {
    return alpha_ <= 0.0;
  }
  return alpha_ >= 1.0;
}