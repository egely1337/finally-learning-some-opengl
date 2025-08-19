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

class Mesh {
protected:
    /* OpenGL Attributes */
    GLuint m_VBO;
    GLuint m_VAO;
    std::vector<glm::vec2> m_Verticies;

    /* Mesh Attributes */
    GLfloat m_MeshScale = 1.f;
    Shader m_Shader;

    /* Scene Attributes */
    Camera2D m_Camera;
public:
    Mesh(std::string& VertexShader, std::string& FragmentShader);
    ~Mesh();

    void Draw();
    void Bind();
    void Destroy();
    
    FORCEINLINE GLfloat& Scale() {return m_MeshScale;};
};

#endif