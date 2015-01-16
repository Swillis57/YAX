//For testing purposes

#include <iostream>
#include <cstdint>

#include "include/GLEW/glew.h"
#include "include/GLFW/glfw3.h"

#include "include/Graphics/GraphicsAdapter.h"

int main()
{
	if (!glewInit()) return -1;
	if (!glfwInit()) return -1;


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* win = glfwCreateWindow(800, 600, "Test", NULL, NULL);
	glfwMakeContextCurrent(win);

	YAX::GraphicsAdapter::FindAdapters();
	auto g = YAX::GraphicsAdapter::Adapters();

	glfwTerminate();
}
