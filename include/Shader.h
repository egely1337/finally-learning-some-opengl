#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <GL/glew.h>

#include <GL.h>
#include <Definitions.h>

#define APP_VERTEX_SHADER GL_VERTEX_SHADER
#define APP_FRAGMENT_SHADER GL_FRAGMENT_SHADER

class Shader{
protected:
    GLuint m_ProgramId;
    char m_ErrorMsg[512];
public:
    Shader();
    ~Shader();
    bool CreateShaderFromSource(std::string VertexShaderSrc, std::string FragmentShaderSrc);
    void Bind();
    void Unbind();
    void Destroy();
    void SetUniform4f(std::string Name, const GLfloat* Matrix4f);
    void SetUniform2f(std::string Name, GLfloat x, GLfloat y);
    void SetUniform1f(std::string Name, GLfloat Val);
    void SetUniform1i(std::string Name, GLint Val);
    FORCEINLINE char* GetErrorMessage() { return m_ErrorMsg; }
};

#endif