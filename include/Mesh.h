#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <GL.h>
#include <Definitions.h>
#include <Shader.h>

class Mesh {
protected:
    GLuint m_VBO;
    GLuint m_VAO;
    std::vector<glm::vec2> m_Verticies;
    Shader m_Shader;
public:
    Mesh();
    ~Mesh();

    void Draw();
    void Bind();
};

#endif