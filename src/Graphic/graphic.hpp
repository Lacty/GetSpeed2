
#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "../Vector/vector.hpp"
#include "../Color/color.hpp"


void drawRect(const vec3f& pos, const vec2f& size, const Color& color);

void drawCircle(const vec3f& center, int vertex_num,
                float radius, float width, const Color& color);