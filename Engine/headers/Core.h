#pragma once

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

class Core
{
public:
	Core();
	~Core();

	bool IsRunning() { return mainWindowIsOpen; };
	GLFWwindow* CreateMainWindow(int width, int height, const char* title);
	void CloseMainWindow();

private:
	const bool InitializeGLFW();
	const bool InitializeGLEW();
	GLFWwindow* mainWindow;
	bool mainWindowIsOpen;

};