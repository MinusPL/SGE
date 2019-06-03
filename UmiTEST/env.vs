#version 330 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec2 uvs;
layout (location = 4) in vec3 tangent;

out vec3 norm;
out vec3 Pos;
out vec2 Uvs;

uniform mat4 model;
uniform mat4 MVP;
uniform mat4 normalModel;

void main()
{
    norm = mat3(normalModel) * normal;
    Pos = vec3(model * vec4(position, 1.0));
    Uvs = uvs;
    gl_Position = MVP * vec4(position, 1.0);
} 