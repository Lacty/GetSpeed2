include_directories(${CMAKE_SOURCE_DIR}/include)

set( CMAKE_C_FLAGS "-Wall -g" )
add_definitions("-std=c++14")

file( GLOB SRCS *.cpp )
file( GLOB HEAD ${CMAKE_SOURCE_DIR}/src/header/*.hpp )

add_executable ( getspeed2 ${SRCS} ${HEAD} )

find_library( COCOA_LIBRARY Cocoa )
find_library( OpenGL_LIBRARY OpenGL )
find_library( IOKIT_LIBRARY IOKit )
find_library( COREVIDEO_LIBRARY CoreVideo )
SET( EXTRA_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} )

target_link_libraries( getspeed2 ${CMAKE_SOURCE_DIR}/lib/OSX/libglfw3.a ${EXTRA_LIBS} )
