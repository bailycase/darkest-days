#pragma once
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "IndexBuffer.hpp"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.hpp"
#include "Window.hpp"

class Renderer
{
public:
    Renderer();
    ~Renderer();
    void Init(GLFWwindow *window);
    void Draw();
    void Update();

private:
    VertexArray m_VAO;
    Shader *m_Shader;
    Camera m_Camera;
    GLFWwindow *m_Window;
    float m_DeltaTime = 0.0f;
    float m_LastFrame = 0.0f;
    void processInput(GLFWwindow *window);
};