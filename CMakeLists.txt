# CMakeList.txt : CMake project for RenderingEngine, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)
project("LumenGame")

set(CMAKE_CXX_STANDARD 14)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(LumenEngine)

# Add source to this project's executable.
add_executable(Lumen Application.cpp)
target_include_directories(Lumen PUBLIC
	"LumenEngine")
target_link_directories(Lumen PRIVATE
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(Lumen PRIVATE
	LumenAPI
	LumenEngine)

# TODO: Add tests and install targets if needed.
