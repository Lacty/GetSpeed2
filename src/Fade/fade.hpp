
#pragma once
#include "../Graphic/graphic.hpp"


class Fade {
public:
  enum class Type {
    In, Out
  };

private:
  Type type_;
  float alpha_;
  float speed_;

public:
  // [speed] is fade speed
  // input 0 ~ 100
  Fade(Type type, float speed = 4.0f);

  void draw();

  bool isFinish();
};