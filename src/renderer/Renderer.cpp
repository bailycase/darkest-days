#include "Renderer.hpp"

Renderer::Renderer() : m_Model("res/models/backpack/backpack.obj")
{
}

void Renderer::Init(GLFWwindow *window)
{
    m_Window = window;
    m_Shader = new Shader("res/shaders/model.shader");
    m_Shader->Bind();
    m_Camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Renderer::Draw()
{
    float currentFrame = glfwGetTime();
    m_DeltaTime = currentFrame - m_LastFrame;
    m_LastFrame = currentFrame;

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view = m_Camera.getViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    // model = glm::rotate(model, (float)glfwGetTime() / 2, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 MVP = projection * view * model;
    m_Shader->SetUniformMat4f("MVP", MVP);
    m_Model.Draw(*m_Shader);
}

void Renderer::Update()
{
    m_Camera.UpdatePosition(m_DeltaTime);
}

Renderer::~Renderer()
{
}
