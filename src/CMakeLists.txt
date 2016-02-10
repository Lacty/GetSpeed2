
# --- Set include directories
#
include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/include/freetype
)


# --- Set compile options
#
if(APPLE)
  set(CMAKE_C_FLAGS "-Wall -g")
  add_definitions("-std=c++14")
endif()


# --- Load Source Files
#
file(GLOB SRCS
            *.cpp
  AppNative/*.cpp
     Camera/*.cpp
      Color/*.cpp
       Font/*.cpp
        Key/*.cpp
      Mouse/*.cpp
      Scene/*.cpp
      Timer/*.cpp
      TwBar/*.cpp
    Utility/*.cpp
     Vector/*.cpp
   LoadPath/*.cpp

  Scene/Title/*.cpp
  Scene/Game/*.cpp
)
file(GLOB HEAD
            *.h            *.hpp
  AppNative/*.h  AppNative/*.hpp
     Camera/*.h     Camera/*.hpp
      Color/*.h      Color/*.hpp
       Font/*.h       Font/*.hpp
        Key/*.h        Key/*.hpp
      Mouse/*.h      Mouse/*.hpp
      Scene/*.h      Scene/*.hpp
      Timer/*.h      Timer/*.hpp
      TwBar/*.h      TwBar/*.hpp
    Utility/*.h    Utility/*.hpp
     Vector/*.h     Vector/*.hpp
   LoadPath/*.h   LoadPath/*.hpp
  
  Scene/Title/*.h  Scene/Title/*.hpp
   Scene/Game/*.h   Scene/Game/*.hpp
)


# --- Set Source Files to Project
#
add_executable(GetSpeed2 ${SRCS} ${HEAD})


# --- Find Libraries
#
if (APPLE)
  find_library(COCOA_LIBRARY     Cocoa)
  find_library(OpenGL_LIBRARY    OpenGL)
  find_library(IOKIT_LIBRARY     IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)
  set(EXTRA_LIBS
    ${COCOA_LIBRARY}
    ${OpenGL_LIBRARY}
    ${IOKIT_LIBRARY}
    ${COREVIDEO_LIBRARY}
    ${CMAKE_SOURCE_DIR}/lib/OSX/libglfw3.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libfreetype.a
    ${CMAKE_SOURCE_DIR}/lib/OSX/libFTGL.a
  )
elseif(MSVC)
  set(EXTRA_LIBS
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/OpenGL32.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/freetyped.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/ftgld.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/glfw3d.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/AntTweakBar64.lib
  )
  set(EXTRA_LIBS_RELEASE
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/OpenGL32.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/freetype.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/ftgl.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/glfw3.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/lib/AntTweakBar64.lib
  )
endif()


# --- Set Library to project
#
target_link_libraries(GetSpeed2 ${EXTRA_LIBS})


# --- copy AntTweakBar.dll to dir[vs2015/src/Debug]
#
# file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/vs2015/src)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/vs2015/src/Debug)
execute_process(COMMAND
  cp ${CMAKE_SOURCE_DIR}/lib/Windows/lib/AntTweakBar64.dll
     ${CMAKE_SOURCE_DIR}/vs2015/src/Debug
)
