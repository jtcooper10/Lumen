cmake_minimum_required(VERSION 3.8)
project("LibRenderer")

set(CMAKE_CXX_STANDARD 14)
set(INCLUDE_DIRS "Dependencies/spdlog/include")

add_subdirectory(Dependencies/spdlog)
add_subdirectory(Dependencies/glfw)

add_library(
	LibRenderer SHARED
	"RenderEngine.cpp"
	"RenderEngine.h"
	"LoggingContext.cpp"
	"LoggingContext.h" "VertexBuffer.h")
add_dependencies(LibRenderer
	spdlog::spdlog
	glfw)
target_compile_definitions(LibRenderer PRIVATE RND_DLL_BUILD)
target_include_directories(LibRenderer PRIVATE
	"Dependencies/spdlog/include"
	"Dependencies/glfw/include")
target_link_libraries(LibRenderer
	spdlog
	glfw)
