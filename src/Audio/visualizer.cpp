
#include "visualizer.hpp"
#include "audio.hpp"
#include "../Graphic/graphic.hpp"


Visualizer::Visualizer(Media* media) :
  media_(media), last_time_(0), height_lower_(1) {
  assert(media_ != nullptr);
}

Visualizer::Visualizer(Media* media, const Vec2f& pos, const Vec2f& size, int split_num) :
  media_(media),
  pos_(pos),
  size_(size),
  split_num_(split_num),
  width_(size.x / split_num),
  height_upper_(size.y),
  height_lower_(1),
  last_time_(0) {
  assert(media_ != nullptr);
}


void Visualizer::draw() {
  float diff_time = last_time_ - media_->currentTime();
  float percent = diff_time / media_->scale();
  size_t size = size_t(media_->getWavData().size() * percent);


  auto data = media_->getWavData().data();

  std::vector<float> samples;
  

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
Visualizer& Visualizer::setHeightUpper(const float limit) {
  height_upper_ = limit;
  return *this;
}
Visualizer& Visualizer::setHeightLower(const float limit) {
  height_lower_ = limit;
  return *this;
}