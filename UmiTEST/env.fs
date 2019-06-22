#version 330 core
layout (location = 0) out vec4 color;
layout (location = 1) out vec4 BrightColor;

in vec3 norm;
in vec3 Position;

uniform vec3 cameraPos;
uniform samplerCube skybox;

void main()
{             
    vec3 I = normalize(Position - cameraPos);
    vec3 R = reflect(I, normalize(norm));
    //color = vec4(texture(skybox, R).rgb, 1.0);
    color = vec4(texture(skybox, R).rgb, 1.0);
    //BrightColor = vec4(texture(skybox, R).rgb, 1.0);
    //color = vec4(norm, 1.0);
}