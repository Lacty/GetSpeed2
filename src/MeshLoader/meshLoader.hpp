
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <picojson.h>


class Mesh;

class MeshLoader {
private:
  std::string path;
  std::string objName;
public:
  MeshLoader() = delete;
  MeshLoader(const std::string& _path,
             const std::string& _objName);

  Mesh get();
};