#include "Window.hpp"
void Window::initWindow()
{
	if (!glfwInit())
	{
		std::cout << "init failed" << std::endl;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_Window = glfwCreateWindow(800, 600, "Darkest Days", NULL, NULL);

	if (&m_Window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(m_Window, &framebuffer_size_callback);
	glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glClearColor(1.0f, 1.1f, 0.75f, 1.0f);
	glEnable(GL_DEPTH_TEST);
}

GLFWwindow *Window::getWindow()
{
	return this->m_Window;
}

Window::Window()
{
	initWindow();
}
