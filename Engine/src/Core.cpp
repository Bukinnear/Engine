#include <iostream>

#include "Core.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Core::Core() : mainWindowIsOpen{false}, mainWindow{nullptr} 
{
}

Core::~Core()
{
	CloseMainWindow();
}

const bool Core::InitializeGLFW()
{
	return glfwInit();
}

const bool Core::InitializeGLEW()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return false;
	}
	std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << "\n";
	return true;
}

GLFWwindow* Core::CreateMainWindow(int width, int height, const char* title)
{
	if (mainWindowIsOpen)
		return mainWindow;

	if (!InitializeGLFW())
		return nullptr;
		
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!mainWindow)
		return nullptr;
		
	mainWindowIsOpen = true;

	glfwMakeContextCurrent(mainWindow);
	if (!InitializeGLEW())
	{
		CloseMainWindow();
		return nullptr;
	}

	glfwGetFramebufferSize(mainWindow, &width, &height);
	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);

	return mainWindow;
}

void Core::CloseMainWindow()
{
	if (!mainWindowIsOpen)
		return;
	
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
	mainWindowIsOpen = false;
}