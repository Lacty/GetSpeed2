# Install script for directory: /Users/yanai/Desktop/GetSpeed2/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/AppNative/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Noncopyable/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Vector/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Color/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Rect/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Key/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Mouse/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Font/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/LoadPath/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Graphic/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Audio/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Random/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/CatmullRom/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/TweakBar/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Utility/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/MainCamera/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Scene/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Fade/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Title/cmake_install.cmake")
  include("/Users/yanai/Desktop/GetSpeed2/xcode/src/Game/cmake_install.cmake")

endif()

