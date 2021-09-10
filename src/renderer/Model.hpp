#pragma once
#include "Shader.hpp"
#include "Mesh.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stb_image.h>

class Model
{
public:
    Model(const std::string &path);
    void Draw(Shader &shader);
    std::vector<MeshTexture> m_TexturesLoaded;

private:
    std::vector<Mesh> m_Meshes;
    std::string m_Dir;

    void LoadModel(std::string path);
    void ProcessNode(aiNode *node, const aiScene *scene);
    Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);
    unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma);
    std::vector<MeshTexture> LoadMaterialTextures(aiMaterial *material, aiTextureType type, std::string typeName);
};