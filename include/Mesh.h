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

    /* Mesh Attributes */
    GLfloat m_MeshScale = 1.f;
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
    void SetScale(GLfloat NewScale);

    FORCEINLINE Shader& GetShader() {return m_Shader;};
    FORCEINLINE GLfloat& Scale() {return m_MeshScale;};
};

#endif