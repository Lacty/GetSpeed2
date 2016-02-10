
#include "loadPath.hpp"


std::string loadAssets(const char* c) {
#if _WINDOWS
  std::string path("../../assets/");
#elif __APPLE__
  std::string path("../../../assets/");
#endif
  path += c;
  return path;
}
