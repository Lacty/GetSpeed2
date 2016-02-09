
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
file(GLOB SRCS *.c *.cpp)
file(GLOB HEAD *.h *.hpp)


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
    ${IOKit_LIBRARY}
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
  )
endif()


# --- Set Library to project
#
target_link_libraries(GetSpeed2 ${EXTRA_LIBS})
