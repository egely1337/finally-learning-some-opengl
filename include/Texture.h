#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <filesystem>

#include <Definitions.h>
#include <GL.h>

#define DESIRED_CHANNELS (int)4
#define TEXTURE_0 0
#define TEXTURE_1 1
#define TEXTURE_2 2

#define TEXTURE_REPEAT_PARAMETERS() \
    { \
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); \
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); \
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); \
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); \
    }

struct Image {
    unsigned int Width;
    unsigned int Height;
    unsigned int Channels;
    unsigned char* Buf;
};

class Texture {
public:
    Texture();
    ~Texture();
    void Bind();
    void Unbind();
    void Load(std::string&& Path);
    static void Initialize();

    FORCEINLINE GLuint GetTextureId() {return m_TextureId;};
protected:
    GLuint m_TextureId;
};

#endif