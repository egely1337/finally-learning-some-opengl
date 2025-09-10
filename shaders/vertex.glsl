#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexPos;

uniform mat4 MVP;
uniform float Scale;

out vec3 Color;
out vec2 TexCoord;

void main() {
    gl_Position = MVP * vec4(aPos * Scale , 0.0, 1.0);
    
    Color = aColor;
    TexCoord = aTexPos;
}