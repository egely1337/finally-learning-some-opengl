#ifndef GL_H
#define GL_H

#include <Definitions.h>
#include <GL/glew.h>

class OpenGL {
public:
    FORCEINLINE static void BindVertexArray(GLint VAO) {
        glBindVertexArray(VAO);
    }
    FORCEINLINE static void GenVertexArray(GLsizei n, GLuint* VAO) {
        glGenVertexArrays(n, VAO);
    }
    FORCEINLINE static void GenBuffers(GLsizei n, GLuint* VBO) {
        glGenBuffers(n, VBO);
    }
    FORCEINLINE static void DeleteShader(GLuint ShaderId) {
        glDeleteShader(ShaderId);
    }
    FORCEINLINE static GLuint CreateShader(GLenum ShaderType) {
        return glCreateShader(ShaderType);
    }
    FORCEINLINE static GLuint CreateProgram() {
        return glCreateProgram();
    }
    FORCEINLINE static void AttachShader(GLuint ProgramId, GLuint ShaderId) {
        glAttachShader(ProgramId, ShaderId);
    }
    FORCEINLINE static void LinkProgram(GLuint ProgramId) {
        glLinkProgram(ProgramId);
    }
    FORCEINLINE static void ShaderSource(GLuint ShaderId, GLsizei Count, const GLchar **Source, const GLint *Lenght) {
        glShaderSource(ShaderId, Count, Source, Lenght);
    }
    FORCEINLINE static void CompileShader(GLuint ShaderId) {
        glCompileShader(ShaderId);
    }
    FORCEINLINE static void DeleteProgram(GLuint ProgramId) {
        glDeleteProgram(ProgramId);
    }
    FORCEINLINE static void UseProgram(GLuint ProgramId) {
        glUseProgram(ProgramId);
    }
    FORCEINLINE static void BindBuffer(GLenum Type, GLuint VBO) {
        glBindBuffer(Type, VBO);
    }
    FORCEINLINE static void BufferData(GLenum Type, GLsizeiptr Size, const GLvoid* Data, GLenum Usage) {
        glBufferData(Type, Size, Data, Usage);
    }
    FORCEINLINE static void EnableVertexAttribArray(GLuint Index) {
        glEnableVertexAttribArray(Index);
    }
    FORCEINLINE static void VertexAttribPointer(GLuint Index, GLint Size, GLenum Type, GLboolean Normalized, GLsizei Stride, const GLvoid *Pointer) {
        glVertexAttribPointer(Index, Size, Type, Normalized, Stride, Pointer);
    }
    FORCEINLINE static void DrawArrays(GLenum Mode, GLuint First, GLuint Count) {
        glDrawArrays(Mode, First, Count);
    }
    FORCEINLINE static void SetUniformMatrix4f(GLuint ProgramId, std::string VariableName, const GLfloat* Ptr) {
        glUniformMatrix4fv(glGetUniformLocation(ProgramId, VariableName.c_str()), 1, GL_FALSE, Ptr);
    }
    FORCEINLINE static void SetUniform1f(GLuint ProgramId, std::string VariableName, GLfloat Val) {
        glUniform1f(glGetUniformLocation(ProgramId, VariableName.c_str()), Val);
    }
    FORCEINLINE static void DeleteBuffers(GLuint Count, GLuint* BufferId) {
        glDeleteBuffers(Count, BufferId);
    }
    FORCEINLINE static void DeleteArrays(GLuint Count, GLuint* ArrayId) {
        glDeleteVertexArrays(Count, ArrayId);
    }
};

#endif