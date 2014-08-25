cmake_minimum_required(VERSION 3.0)

project(XNA.Framework)

option(Debug "Debug" ON)
option(Compile_GLFW "Compile_GLFW" ON)
option(Compile_GLEW "Compile_GLEW" ON)

set(XNA_FRAMEWORK_DIR ${CMAKE_SOURCE_DIR}/Framework/)


if(Compile_GLEW)
	add_subdirectory(external/glew/)
endif()

if(Compile_GLFW)
	add_subdirectory(external/glfw)
endif()

include_directories(${XNA_FRAMEWORK_DIR}/include
	${XNA_FRAMEWORK_DIR}/include/Audio
	${XNA_FRAMEWORK_DIR}/include/Curves
	${XNA_FRAMEWORK_DIR}/include/Design
	${XNA_FRAMEWORK_DIR}/include/Geometry
	${XNA_FRAMEWORK_DIR}/include/Graphics
	${XNA_FRAMEWORK_DIR}/include/Input
	${XNA_FRAMEWORK_DIR}/include/Math
	${XNA_FRAMEWORK_DIR}/include/Media
	${XNA_FRAMEWORK_DIR}/include/Net
	${XNA_FRAMEWORK_DIR}/include/Storage
	${XNA_FRAMEWORK_DIR}/include/GLFW
	${XNA_FRAMEWORK_DIR}/include/GL
)

link_directories(${XNA_FRAMEWORK_DIR}/lib)

add_subdirectory(${XNA_FRAMEWORK_DIR})

