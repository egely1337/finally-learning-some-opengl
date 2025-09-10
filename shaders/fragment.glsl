#version 330 core

/* In & Out */
in vec3 Color;
in vec2 TexCoord;
out vec4 FragColor;

/* Our Texture */
uniform sampler2D Texture;

void main() {
    FragColor = texture(Texture, TexCoord);
}