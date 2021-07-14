#include "Window.hpp"
void Window::initWindow()
{
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	if (!glfwInit())
	{
		std::cout << "init failed" << std::endl;
	}
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	m_Window = glfwCreateWindow(WIDTH, HEIGHT, "Darkest Days", NULL, NULL);

	if (&m_Window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
	}
	// glfwMakeContextCurrent(m_Window);
	// glfwSwapInterval(1);
	// if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	// {
	// 	std::cout << "Failed to initialize GLAD" << std::endl;
	// }
	// glViewport(0, 0, 800, 600);
	// glfwSetFramebufferSizeCallback(m_Window, &framebuffer_size_callback);
}

GLFWwindow &Window::getWindow()
{
	return *m_Window;
}

Window::Window()
{
}

void Window::cleanupWindow()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}