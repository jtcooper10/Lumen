cmake_minimum_required(VERSION 3.8)
project("LumenEngine")

set(CMAKE_CXX_STANDARD 14)
set(INCLUDE_DIRS "Dependencies/spdlog/include")

add_subdirectory(Dependencies/spdlog)
add_subdirectory(Dependencies/glfw)

add_library(LumenAPI STATIC
	"Lumen.h"
	"Lumen.cpp")

add_library(
	LumenEngine SHARED
	"LoggingContext.h"
	"LoggingContext.cpp"
	"LumenCore.h"
	"LumenCore.cpp"
	"ApplicationContext.h"
	"ApplicationContext.cpp")
add_dependencies(LumenEngine
	spdlog::spdlog
	glfw)
target_compile_definitions(LumenEngine PRIVATE LUMEN_DLL_BUILD)
target_include_directories(LumenEngine PRIVATE
	"Dependencies/spdlog/include"
	"Dependencies/glfw/include")
target_link_libraries(LumenEngine
	spdlog
	glfw)
