#include "Renderer.hpp"

Renderer::Renderer() : m_Model("res/models/backpack.obj")
{
}

void Renderer::Init(GLFWwindow *window)
{
    m_Window = window;
    // VertexBuffer vb(vertices, sizeof(vertices));
    // VertexBufferLayout layout;
    // IndexBuffer ib(indices, sizeof(indices));
    // layout.Push<float>(3);
    // layout.Push<float>(3);
    // layout.Push<float>(2);
    // m_VAO.CreateArray();
    // m_VAO.AddBuffer(vb, layout);
    m_Shader = new Shader("res/shaders/basic.shader");
    m_Shader->Bind();

    // Texture texture("res/textures/container.jpg");
    // texture.bind();

    m_Camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Renderer::Draw()
{
    float currentFrame = glfwGetTime();
    m_DeltaTime = currentFrame - m_LastFrame;
    m_LastFrame = currentFrame;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view = m_Camera.getViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 MVP = projection * view * model;
    m_Shader->SetUniformMat4f("MVP", MVP);
    m_Model.Draw(*m_Shader);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // m_Shader->Bind();
    // m_VAO.bind();
    // for (unsigned int i = 0; i < 10; i++)
    // {
    //     glm::mat4 model = glm::mat4(1.0f);
    //     model = glm::translate(model, cubePositions[i]);
    //     float angle = 20.0f * i;
    //     // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(i, 0.3f, 0.5f));
    //     glm::mat4 MVP = projection * view * model;
    //     m_Shader->SetUniformMat4f("MVP", MVP);
    //     glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));
    // }
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);
}

void Renderer::Update()
{
    m_Camera.UpdatePosition(m_DeltaTime);
}

Renderer::~Renderer()
{
}
