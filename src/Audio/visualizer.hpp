
#pragma once
#include "../Vector/vector.hpp"


class Media;

class Visualizer {
private:
  Media* media_;
  Vec2f  pos_;
  Vec2f  size_;
  int    split_num_;
  float  height_limit_;

public:
  Visualizer() = default;
  Visualizer(const Vec2f& pos, const Vec2f& size, int split_num);
};