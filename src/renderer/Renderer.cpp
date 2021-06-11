#include "Renderer.hpp"

glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
glm::vec3 translation(200, 200, 0);

unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 2, // first triangle
    2, 3, 0  // second triangle
};

void Renderer::Render()
{
}

void Renderer::Init()
{
}

void Renderer::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    m_VAO.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);
    // glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
    // glm::mat4 mvp = proj * view * model;
    // m_Shader.SetUniformMat4f("u_MVP", mvp);
}

Renderer::~Renderer()
{
}

Renderer::Renderer()
{
    float vertices[] = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
        0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f   // top left
    };

    float texCoords[] = {0.0f,
                         0.0f,
                         1.0f,
                         0.0f,
                         0.5f,
                         1.0f};

    VertexBuffer vb(vertices, sizeof(vertices));
    VertexBufferLayout layout;
    IndexBuffer ib(indices, sizeof(indices));
    layout.Push<float>(3);
    layout.Push<float>(3);
    layout.Push<float>(2);
    m_VAO.AddBuffer(vb, layout);
    Shader m_Shader = Shader("res/shaders/basic.shader");
    m_Shader.Bind();

    Texture texture("res/textures/container.jpg");
    texture.bind();
}
