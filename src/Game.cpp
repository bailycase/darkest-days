#include "Game.hpp"
#include <memory>

Game::Game()
{
    Window *window = new Window();
    m_Window = window->getWindow();
    m_InputHandler = new InputHandler(m_Window);
    m_Renderer = std::make_unique<Renderer>();
    m_Renderer->Init(m_Window);
}

Game::~Game()
{
}

void Game::Run()
{
    Lmgui::Init(m_Window);
    while (!glfwWindowShouldClose(m_Window))
    {
        glfwSwapBuffers(m_Window);
        m_Renderer->Draw();
        Lmgui::RenderImgui();
        glfwPollEvents();
        m_Renderer->Update();
    }
    glfwTerminate();
}

GLFWwindow *Game::getWindow()
{
    return m_Window;
}
