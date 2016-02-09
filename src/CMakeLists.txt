
if(APPLE)
add_definitions("-std=c++14")
endif()

file(GLOB SRCS *.c *.cpp)
file(GLOB HEAD *.h *.hpp)

add_executable(GetSpeed2 ${SRCS} ${HEAD})
