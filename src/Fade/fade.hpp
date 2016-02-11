
#pragma once
#include <GLFW/glfw3.h>


class AppNative;

class Fade {
public:
  enum class Type {
    In, Out
  };
  
private:
  Type type;
  float alpha;
  float speed;
  
public:
  // [speed] is fade speed
  // input 0 ~ 100
  Fade(Type _type, float _speed = 14);
  
  void draw(AppNative* app);
  
  bool isFinish();
};
