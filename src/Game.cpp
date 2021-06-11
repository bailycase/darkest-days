#include "Game.hpp"

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
};

Game::Game() : m_Window(glfwCreateWindow(800, 600, "Darkest Days", NULL, NULL))
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
    glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
}

Game::~Game()
{
}

void Game::Run()
{
    Renderer renderer;
    while (!glfwWindowShouldClose(m_Window))
    {
        processInput(m_Window);
        renderer.Draw();
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Game::handleEvents()
{
}
