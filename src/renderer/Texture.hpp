#pragma once
#include <string>

class Texture
{
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char *m_LocalBuffer;
    int m_Width, m_Height, m_Channels;

public:
    Texture(const std::string &path);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind();
};