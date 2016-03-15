
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
  static double last_time;    // �O�t���[�����̉����̍Đ�����
  static double diff_time;    // �O�t���[���ƌ��݃t���[���̍Đ����Ԃ̍�
  static double percent;      // ��̍�����S�̂̉��p�[�Z���g�𗬂��I�������
  static double time_percent; // �S�̂�1�Ƃ���0~�̃p�[�Z���e�[�W
  static int count;           // �t���[���v���p
  static size_t size = 8820;  // �����̗v�f�� �t���[���������Čv�Z�ʂ��������ꍇ�A
                              // ���̕��܂��t���[����������̂Ōv�Z�͂��������ߑł��Ƃ���
  static size_t index;        // last���̗v�f�ԍ�
  
  // FFT�̌��ʂ��i�[����R���e�i
  static std::vector<float> samples;
  static std::vector<std::complex<float>> freqvec;

  // currentTime�̐��\�������̂�
  // �t���[�������������Ă���
  if (count == 3) {
    diff_time = media_->currentTime() - last_time;
    last_time = media_->currentTime();
    percent = diff_time / media_->scale();
    time_percent = media_->currentTime() / media_->scale();
    //size = media_->getWavData().size() * percent;
    index = media_->getWavData().size() * time_percent;
    count = 0;
  } count++;

  if (diff_time <= 0) diff_time = 0; // stop���Ƀ}�C�i�X�ɂȂ�̂ŁA���}���u
  if (diff_time) is_data_available_ = true;
  else is_data_available_ = false;

  // �f�[�^���L���ł���ꍇ�̂�FFT�����s����
  if (is_data_available_) {
    samples.clear();
    freqvec.clear();

    // �����̍Ō�ɗv�f����U��؂�Ȃ��悤�ɂ���
    if (index + size > media_->getWavData().size()) {
      int diff = media_->getWavData().size() - index + size;
      size += diff;
    }
    
    // �f�[�^���擾����
    auto data = media_->getWavData().data();

    // �擾�����f�[�^����v�Z����f�[�^�����R�s�[����
    for (int i = index; i < index + size; i += 2) {
      samples.push_back(wchar_t(data[i] + data[i + 1]));
    }

    // FFT�����s����
    Eigen::FFT<float> fft;
    fft.fwd(freqvec, samples);
  }


  for (size_t i = 0; i < size_.x; i++) {
    std::cout << (freqvec.size() / size_.x) << std::endl;
    float x = freqvec.size() == 0 ? 1 : freqvec[int(i * (freqvec.size() / size_.x))].real();
    float y = freqvec.size() == 0 ? 1 : freqvec[int(i * (freqvec.size() / size_.x))].imag();

    float p = std::sqrt(x * x + y * y); // �U��
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