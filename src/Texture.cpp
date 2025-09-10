#include <Texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stbi_image.h>

void Texture::Bind() {
    glActiveTexture(GL_TEXTURE0);
    OpenGL::BindTexture(GL_TEXTURE_2D, m_TextureId);
}

void Texture::Unbind() {
    OpenGL::BindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Load(std::string&& Path) {
    /* Load Image */
    Image image;
    {
        image.Buf = stbi_load(Path.c_str(), (int*)&image.Width, (int*)&image.Height, (int*)&image.Channels, DESIRED_CHANNELS);
        APP_ASSERT(image.Buf && "Failed to open file\n");
    }

    /* Create Texture in OpenGL */
    OpenGL::GenTexture(1, &m_TextureId);
    APP_ASSERT(m_TextureId > 0 && "Failed to generate texture.\n");
    OpenGL::BindTexture(GL_TEXTURE_2D, m_TextureId);

    /* Parameters */
    TEXTURE_REPEAT_PARAMETERS();

    /* Bind Texture Source */
    OpenGL::TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.Width, image.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.Buf);
}

void Texture::Initialize()
{
    stbi_set_flip_vertically_on_load(true);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
}
