# CMakeList.txt : CMake project for RenderingEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project ("RenderingEngine")

set(CMAKE_CXX_STANDARD 14)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(LibRenderer)

# Add source to this project's executable.
add_executable(RenderingEngine Application.cpp)
target_include_directories(RenderingEngine PUBLIC "LibRenderer")
target_link_directories(RenderingEngine PRIVATE
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(RenderingEngine PRIVATE LibRenderer)

# TODO: Add tests and install targets if needed.
