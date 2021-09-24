#include "RenderSystem.hpp"

void RenderSystem::Init(GLFWwindow *window)
{
    m_Window = window;
    // m_Shader = new Shader("res/shaders/model.shader");
    // m_Shader->Bind();
    // m_Camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void RenderSystem::Update()
{
}

void RenderSystem::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
