#pragma once
#include <GLFW/glfw3.h>
#include "Renderer/Renderer.hpp"
#include <glad/glad.h>
#include <iostream>
#include "Renderer/Window.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/LmGui.hpp"

class Game
{
public:
    Game();
    ~Game();
    void Run();
    void handleEvents();
    GLFWwindow *getWindow();

private:
    GLFWwindow *m_Window;
    Renderer *m_Renderer = nullptr;
};