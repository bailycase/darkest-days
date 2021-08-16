#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../InputHandler/InputHandler.hpp"

class Window
{
public:
	Window();
	void initWindow();
	GLFWwindow *getWindow();

private:
	GLFWwindow *m_Window;
	static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
};