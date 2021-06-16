#pragma once
#include <GLFW/glfw3.h>
#include "Renderer/Renderer.hpp"
#include <glad/glad.h>
#include <iostream>
#include "Renderer/VertexArray.hpp"
#include "Renderer/LmGui.hpp"

class Game
{
public:
    Game();
    ~Game();
    void Run();
    void handleEvents();

private:
    GLFWwindow *m_Window;
    Renderer *m_Renderer = nullptr;
    static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
};