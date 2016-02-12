
#include "meshLoader.hpp"
#include "../Mesh/mesh.hpp"


MeshLoader::MeshLoader(const std::string& _path,
                       const std::string& _objName) :
path(_path),
objName(_objName) {
  std::cout << objName << std::endl;
}


Mesh MeshLoader::get() {
  std::stringstream data;
  std::ifstream     file;

  file.open(path.c_str(), std::ios::binary);
  if(!file.is_open()) {
    std::cout << "file didn't open" << std::endl;
    exit(1);
  }

  data << file.rdbuf();
  file.close();

  picojson::value val;
  data >> val;

  auto obj = val.get<picojson::object>();

  auto sclae = obj["Scale"].get<double>();
  auto vertex = obj["Vertex"].get<picojson::array>();
  auto color  = obj["Color"].get<picojson::array>();

  Mesh mesh;
  for (const auto& it : vertex) {
    mesh.vertex.push_back(it.get<double>() * sclae);
  }
  for (const auto& it : color) {
    mesh.color.push_back(it.get<double>());
  }

  return mesh;
}