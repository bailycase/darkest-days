#include "Renderer.hpp"

float vertices[] = {
    // start first quad
    -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // 1 a
    0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,   // 2 a
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 3 a
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,  // 1 b
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // 2 b
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // 3 b
    // end
    // start second quad
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // 1 c
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,   // 2 c
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 3 c
    -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,  // 1 d
    -0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // 2 d
    0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // 3 d
    //end
    // start third quad
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 1 c
    -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3 c
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // 1 c
    -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,   // 3 c
    // end
    //start 4th quad
    0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 1 c
    0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3 c
    0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // 1 c
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,   // 3 c
    //end
    //start 5th quad
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // 1 c
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,   // 3 c
    0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 1 c
    -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3 c
    //end
    //start 6th quad
    -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // 1 c
    0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,   // 3 c
    0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 1 c
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 2 c
    -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3 c
    //end
};

glm::vec3 cubePositions[] = {
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f, 2.0f, -2.5f),
    glm::vec3(1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f),
};
unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 2, // first triangle
    2, 3, 0, // second triangle

};

Renderer::Renderer()
{
}

void Renderer::Init(GLFWwindow *window)
{
    m_Window = window;
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
    m_VAO.CreateArray();
    m_VAO.AddBuffer(vb, layout);
    m_Shader = new Shader("res/shaders/basic.shader");
    m_Shader->Bind();

    Texture texture("res/textures/container.jpg");
    texture.bind();

    m_Camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Renderer::Draw()
{
    // update delta time
    float currentFrame = glfwGetTime();
    m_DeltaTime = currentFrame - m_LastFrame;
    m_LastFrame = currentFrame;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // camera/view transformation
    glm::mat4 view = m_Camera.getViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    m_Shader->Bind();
    m_VAO.bind();
    for (unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(i, 0.3f, 0.5f));
        glm::mat4 MVP = projection * view * model;
        m_Shader->SetUniformMat4f("MVP", MVP);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));
    }
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);
}

void Renderer::Update()
{
    m_Camera.UpdatePosition(m_DeltaTime);
}

Renderer::~Renderer()
{
}
