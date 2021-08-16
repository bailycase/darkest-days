#include "Game.hpp"
#include <memory>

Game::Game() : m_Renderer(std::make_unique<Renderer>())
{
    Window *window = new Window();
    m_Window = window->getWindow();
    m_InputHandler = &InputHandler(m_Window);
    m_Renderer->Init(m_Window);
}

Game::~Game()
{
}

void Game::Run()
{

    while (!glfwWindowShouldClose(m_Window))
    {
        m_Renderer->Draw();
        // Lmgui::RenderImgui();
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
        m_Renderer->Update();
    }
    glfwTerminate();
}

GLFWwindow *Game::getWindow()
{
    return m_Window;
}
