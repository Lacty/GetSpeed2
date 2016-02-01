
#pragma once
#include <iostream>
#include <string>
#include <chrono>


class Timer {
private:
  std::chrono::high_resolution_clock::time_point start_point;
  std::chrono::high_resolution_clock::time_point stop_point;
  std::chrono::milliseconds                      stop_duar;
  
  bool isStart;
  bool isStop;

public:
  Timer() = default;

  void start();
  void stop();
  void end();

  const double getCurrentTime() const;
};
