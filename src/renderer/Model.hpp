#pragma once
#include "Shader.hpp"
#include "Mesh.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
    Model(const std::string &path);
    void Draw(Shader &shader);

private:
    std::vector<Mesh> m_Meshes;
    std::string m_Dir;

    void LoadModel(std::string path);
    void ProcessNode(aiNode *node, const aiScene *scene);
    Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<MeshTexture> LoadMaterialTextures(aiMaterial *material, aiTextureType type, std::string typeName);
};