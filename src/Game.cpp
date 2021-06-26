#include "Game.hpp"

Game::Game()
{
    Window *window = new Window();
    m_Window = window->getWindow();
}

Game::~Game()
{
}

void Game::Run()
{
    Renderer renderer;
    renderer.Init(m_Window);
    // for (unsigned int i = 0; i < 32; i++)
    // {
    //     renderer.submitQuad()
    // }

    while (!glfwWindowShouldClose(m_Window))
    {
        // processInput(m_Window);
        renderer.Draw();
        // Lmgui::RenderImgui();
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Game::handleEvents()
{
}

GLFWwindow *Game::getWindow()
{
    return m_Window;
}
