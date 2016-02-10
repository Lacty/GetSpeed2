
#include "loadPath.hpp"


std::string loadAssets(const char* c) {
#if _WINDOWS
  std::string path("../../assets/");
#else
  std::string path("../../../assets/");
#endif
  path += c;
  return path;
}
