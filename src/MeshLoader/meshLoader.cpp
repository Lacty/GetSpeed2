
#include "meshLoader.hpp"
#include <map>
#include <vector>


MeshLoader::MeshLoader(const std::string& _path,
                       const std::string& _objName) :
path(_path),
objName(_objName) {
  std::cout << objName << std::endl;
}


Mesh<std::vector<float>> MeshLoader::get() {
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

  auto scale  = obj["Scale"].get<double>();
  auto vertex = obj["Vertex"].get<picojson::array>();
  auto color  = obj["Color"].get<picojson::array>();
  auto index  = obj["Index"].get<picojson::array>();

  Mesh<std::vector<float>> mesh;

  std::map<int, std::vector<double>> vertex_list;
  int k = 1;
  for(auto it : vertex) {
    for(auto d : it.get<picojson::array>()) {
      vertex_list[k].push_back(d.get<double>());
    }
    k++;
  }
  for(auto ind : index) {
    for(auto i : ind.get<picojson::array>()) {
      for(auto it : vertex_list[i.get<double>()]) {
        mesh.vertex.push_back(it * scale);
      }
    }
  }

  for(int i = 0; i < mesh.VertexNum(); i++) {
    for(auto it : color) {
      mesh.color.push_back(it.get<double>());
    }
  }

  return mesh;
}