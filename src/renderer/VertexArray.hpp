#pragma once
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

class VertexArray
{
private:
    GLuint m_VertexArrayID;
    // std::vector<VertexBuffer *> m_Buffers;

public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout);
    void CreateArray();

    void bind() const;
    void unbind() const;
};