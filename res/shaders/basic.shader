#shader vertex
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec4 ourColor;
out vec2 TexCoord;

uniform mat4 MVP;

void main()
{
    gl_Position =  MVP * vec4(position, 1.0f);
    ourColor = aColor;
    TexCoord = aTexCoord;
};


#shader fragment
#version 330 core

out vec4 vertexColor;
in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    vertexColor = texture(ourTexture, TexCoord);
};
