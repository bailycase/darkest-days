#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <memory>
#include "Renderer/Window.hpp"
#include "Renderer/vulkan/VulkanRenderer.hpp"

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
    // Renderer *m_Renderer = nullptr;
};