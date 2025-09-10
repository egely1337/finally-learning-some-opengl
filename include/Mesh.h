#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <GL.h>
#include <Definitions.h>
#include <Camera2D.h>
#include <Shader.h>
#include <Vertex.h>
#include <Texture.h>

class Mesh {
protected:
    /* OpenGL Attributes */
    GLuint m_VBO;
    GLuint m_VAO;
    std::vector<Vertex2f> m_Verticies;

    /* Transform */
    glm::vec2 m_Position = glm::vec2(0.f, 0.f);
    GLfloat m_Scale = 1.f;
    GLfloat m_Rotation;

    /* Shader and Texture */
    Shader m_Shader;
    Texture m_Texture;

    /* Scene Attributes */
    Camera2D m_Camera;
public:
    Mesh();
    ~Mesh();

    void Draw();
    void Bind();
    void Destroy();

    FORCEINLINE Shader& GetShader() {return m_Shader;};
    FORCEINLINE glm::vec2& Position() {return m_Position;};
    FORCEINLINE GLfloat& Scale() {return m_Scale;};
};

#endif