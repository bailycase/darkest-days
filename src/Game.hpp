#pragma once
#include <GLFW/glfw3.h>
#include "renderer/Renderer.hpp"
#include <glad/glad.h>
#include <iostream>
#include <memory>
#include "renderer/Window.hpp"
#include "renderer/VertexArray.hpp"
#include "renderer/LmGui.hpp"
#include "InputHandler/InputHandler.hpp"

class Game
{
public:
    Game();
    ~Game();
    void Run();
    GLFWwindow *getWindow();

private:
    GLFWwindow *m_Window;
    // Renderer *m_Renderer = nullptr;
    // std::unique_ptr<GLFWwindow> m_Window;
    std::unique_ptr<Renderer> m_Renderer;
    InputHandler *m_InputHandler;
};