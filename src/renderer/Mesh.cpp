#include "Mesh.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<MeshTexture> textures)
{
    this->m_Vertices = vertices;
    this->m_Indices = indices;
    this->m_Textures = textures;
    SetupMesh();
}

void Mesh::SetupMesh()
{
    VertexBuffer vb(&m_Vertices, sizeof(m_Vertices));
    VertexArray va = m_VAO;
    m_VAO.CreateArray();
    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(3);
    layout.Push<float>(2);
    m_VAO.AddBuffer(vb, layout);
}

void Mesh::Draw(Shader &shader)
{
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for (unsigned int i = 0; i < m_Textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        std::string number;
        std::string name = m_Textures[i].type;

        if (name == "texture_diffuse")
        {
            number = std::to_string(diffuseNr++);
        }
        else if (name == "texture_specular")
        {
            number = std::to_string(specularNr++);
        }

        // shader.SetUniformMat4f
        glBindTexture(GL_TEXTURE_2D, m_Textures[i].id);
    }

    glActiveTexture(GL_TEXTURE0);
    m_VAO.bind();
    glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, &m_Indices);
    glBindVertexArray(0);
}