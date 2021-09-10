#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
private:
    std::unordered_map<std::string, int> m_UniformLocationCache;

public:
    Shader(const std::string &filepath);
    Shader();
    ~Shader();
    void Bind() const;
    void Unbind() const;
    unsigned int m_RendererID;

    //handle uniforms
    void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix);

private:
    int GetUniformLocation(const std::string &name);
    static unsigned int CompileShader(unsigned int type, const std::string &source);
    static ShaderProgramSource ParseShader(const std::string &filepath);
    static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
};