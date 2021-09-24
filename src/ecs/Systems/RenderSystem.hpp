#pragma once
#include "renderer/VertexArray.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../System.hpp"

class RenderSystem : public System
{
public:
    void Init(GLFWwindow *window);
    void Update();
    void Draw();

private:
    VertexArray m_VAO;
    GLFWwindow *m_Window;
    Entity m_Camera;
    float m_DeltaTime = 0.0f;
    float m_LastFrame = 0.0f;
};