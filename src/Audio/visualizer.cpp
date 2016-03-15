
#include "visualizer.hpp"
#include "audio.hpp"
#include "../Graphic/graphic.hpp"


Visualizer::Visualizer(Media* media) :
  media_(media), height_lower_(1), is_data_available_(false) {
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
  is_data_available_(false) {
  assert(media_ != nullptr);
}


void Visualizer::draw() {
  static double last_time;    // 前フレーム時の音生の再生時間
  static double diff_time;    // 前フレームと現在フレームの再生時間の差
  static double percent;      // 上の差から全体の何パーセントを流し終わったか
  static double time_percent; // 全体を1として0~のパーセンテージ
  static int count;           // フレーム計測用
  static size_t size = 8820;  // 差分の要素数 フレーム落ちして計算量が増えた場合、
                              // その分またフレーム落ちするので計算はさせず決め打ちとする
  static size_t index;        // last時の要素番号
  
  // FFTの結果を格納するコンテナ
  static std::vector<float> samples;
  static std::vector<std::complex<float>> freqvec;

  // currentTimeの性能が悪いので
  // フレーム制限をかけている
  if (count == 3) {
    diff_time = media_->currentTime() - last_time;
    last_time = media_->currentTime();
    percent = diff_time / media_->scale();
    time_percent = media_->currentTime() / media_->scale();
    //size = media_->getWavData().size() * percent;
    index = media_->getWavData().size() * time_percent;
    count = 0;
  } count++;

  if (diff_time <= 0) diff_time = 0; // stop時にマイナスになるので、応急処置
  if (diff_time) is_data_available_ = true;
  else is_data_available_ = false;

  // データが有効である場合のみFFTを実行する
  if (is_data_available_) {
    samples.clear();
    freqvec.clear();

    // 音生の最後に要素数を振り切らないようにする
    if (index + size > media_->getWavData().size()) {
      int diff = media_->getWavData().size() - index + size;
      size += diff;
    }
    
    // データを取得する
    auto data = media_->getWavData().data();

    // 取得したデータから計算するデータだけコピーする
    for (int i = index; i < index + size; i += 2) {
      samples.push_back(wchar_t(data[i] + data[i + 1]));
    }

    // FFTを実行する
    Eigen::FFT<float> fft;
    fft.fwd(freqvec, samples);
  }


  for (size_t i = 0; i < size_.x; i++) {
    std::cout << (freqvec.size() / size_.x) << std::endl;
    float x = freqvec.size() == 0 ? 1 : freqvec[int(i * (freqvec.size() / size_.x))].real();
    float y = freqvec.size() == 0 ? 1 : freqvec[int(i * (freqvec.size() / size_.x))].imag();

    float p = std::sqrt(x * x + y * y); // 振幅
    drawLine(Vec2f(i * (freqvec.size() / size_.x) + pos_.x,
                   pos_.y),
             Vec2f(i * (freqvec.size() / size_.x) + pos_.x,
                   p * 0.0001f + pos_.y));
  }
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