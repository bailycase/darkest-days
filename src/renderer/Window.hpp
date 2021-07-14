#pragma once
#include <vulkan.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window();
	void initWindow();
	void cleanupWindow();
	GLFWwindow &getWindow();

private:
	GLFWwindow *m_Window;
	static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
};