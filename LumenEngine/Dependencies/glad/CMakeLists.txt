cmake_minimum_required(VERSION 3.18)
project("GLAD")


add_library(glad STATIC
	"glad.c"
	"include/glad/glad.h")
target_include_directories(glad PUBLIC
	"include")
