
#include "loadPath.hpp"


std::string loadAssets(const char* c) {
#if _WINDOWS
  std::string path("../../assets/");
#elif _APPLE
#endif
  path += c;
  return path;
}
