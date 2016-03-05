
#pragma once
#include <random>
#include "../Noncopyable/noncopyable.hpp"


class Random : public Noncopyable {
public:
  std::random_device rand_;
  std::mt19937_64    mt_;
  
  Random();
};