#include <iostream>

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"


void error_callback(int error, const char* description)
{
	std::cout << "ERROR: " << error << ", Message: " << description;
}

int main()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) { return 1; }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);
	if (!window) { return 1; }

	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	std::cout << "Status: Using GLEW %s\n" << glewGetString(GLEW_VERSION);

	while (!glfwWindowShouldClose(window))
	{
		// main loop
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}