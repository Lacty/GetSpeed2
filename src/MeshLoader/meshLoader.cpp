
#include "meshLoader.hpp"
#include <map>
#include <vector>


MeshLoader::MeshLoader(const std::string& _path,
                       const std::string& _objName) :
path(_path),
objName(_objName) {
  std::cout << objName << std::endl;
}