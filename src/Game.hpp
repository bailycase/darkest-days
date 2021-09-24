#pragma once
#include <GLFW/glfw3.h>
#include "ecs/Systems/RenderSystem.hpp"
#include "ecs/Managers/Coordinator.hpp"
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
    std::shared_ptr<RenderSystem> m_Renderer;
    // std::shared_ptr<PlayerControlSystem> m_PlayerControlSystem;
    InputHandler *m_InputHandler;
    Coordinator m_Coordinator;
    Lmgui Imgui;
};