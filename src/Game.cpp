#include "Game.hpp"
#include <memory>

Game::Game()
{
    this->m_Coordinator = Coordinator();
    this->m_Window = Window().getWindow();
    this->m_InputHandler = new InputHandler(m_Window);

    m_Coordinator.Init();
    m_Renderer = m_Coordinator.RegisterSystem<RenderSystem>();
    m_Renderer->Init(m_Window);
}

Game::~Game()
{
}

void Game::Run()
{
    Lmgui().Init(m_Window);
    while (!glfwWindowShouldClose(m_Window))
    {
        glfwSwapBuffers(m_Window);
        m_Renderer->Draw();
        Lmgui().RenderImgui(&m_Coordinator);
        glfwPollEvents();
        m_Renderer->Update();
    }
    glfwTerminate();
}

GLFWwindow *Game::getWindow()
{
    return m_Window;
}
