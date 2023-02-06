#include <iostream>

#include "Core.h"

void error_callback(int error, const char* description)
{
	std::cout << "ERROR: " << error << ", Message: " << description;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{
	glfwSetErrorCallback(error_callback);
	
	auto core = Core();
	auto window = core.CreateMainWindow(640, 480, "My Window");
	if (!window) 
	{ 
		core.CloseMainWindow();
		return 1; 
	}

	while (!glfwWindowShouldClose(window))
	{
		// main loop
		processInput(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	core.CloseMainWindow();
	return 0;
}