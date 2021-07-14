#include "VertexArray.hpp"
#include <iostream>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_VertexArrayID);
}

VertexArray::~VertexArray()
{
    // for (unsigned int i = 0; i < m_Buffers.size(); ++i)
    // {
    //     delete m_Buffers[i];
    // }

    glDeleteVertexArrays(1, &m_VertexArrayID);
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    bind();
    vb.bind();
    const auto &elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto &element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void *)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::bind() const
{
    glBindVertexArray(m_VertexArrayID);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}
