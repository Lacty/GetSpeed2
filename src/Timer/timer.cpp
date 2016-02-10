
#include "timer.hpp"


void Timer::start() {
  typedef std::chrono::high_resolution_clock _clock;
  
  isStart = true;
  if (isStop) {
    stop_duar = std::chrono::duration_cast<std::chrono::milliseconds>(_clock::now() - stop_point);
    start_point += stop_duar;
    isStop = false;
  }
  else {
    start_point = _clock::now();
  }
}

void Timer::stop() {
  typedef std::chrono::high_resolution_clock _clock;

  if (isStop) return;
  
  isStop  = true;
  isStart = false;
  stop_point = _clock::now();
}

void Timer::end() {
  isStart = false;
  isStop  = false;
}

const double Timer::getCurrentTime() const {
  typedef std::chrono::high_resolution_clock _clock;

  if (!isStart) return 0;
  auto time = std::chrono::duration_cast<std::chrono::milliseconds>(_clock::now() - start_point);
  return time.count();
}
