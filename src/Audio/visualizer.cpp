
#include "visualizer.hpp"
#include "audio.hpp"
#include "../Graphic/graphic.hpp"


Visualizer::Visualizer(Media* media) :
  media_(media), last_time_(0) {
  assert(media_ != nullptr);
}

Visualizer::Visualizer(Media* media, const Vec2f& pos, const Vec2f& size, int split_num) :
  media_(media),
  pos_(pos),
  size_(size),
  split_num_(split_num),
  width_(size.x / split_num),
  height_limit_(size.y),
  last_time_(0) {
  assert(media_ != nullptr);
}


void Visualizer::draw() {
  

  last_time_ = media_->currentTime();
}

Visualizer& Visualizer::setPos(const Vec2f& pos) {
  pos_ = pos;
  return *this;
}
Visualizer& Visualizer::setSize(const Vec2f& size) {
  size_ = size;
  return *this;
}
Visualizer& Visualizer::setLineWidth(const float width) {
  width_ = width;
  return *this;
}
Visualizer& Visualizer::setSplitNum(const int num) {
  split_num_ = num;
  return *this;
}
Visualizer& Visualizer::setHeightLight(const float limit) {
  height_limit_ = limit;
  return *this;
}