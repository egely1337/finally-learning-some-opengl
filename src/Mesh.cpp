#include <Mesh.h>

Mesh::Mesh()
{
    NOT_IMPLEMENTED();
}

Mesh::~Mesh()
{
    NOT_IMPLEMENTED();
}

void Mesh::Draw()
{
    OpenGL::BindVertexArray(m_VAO);
    OpenGL::DrawArrays(GL_POLYGON, 0, m_Verticies.size());
    OpenGL::BindVertexArray(0);
}

void Mesh::Bind()
{
    m_Verticies.push_back(glm::vec2(-1, 0));
    m_Verticies.push_back(glm::vec2(0, 1));
    m_Verticies.push_back(glm::vec2(1, 0));
    APP_ASSERT(m_Verticies.size() > 0 && "You should set verticies first.");

    /* Create VAO and VBO. */
    OpenGL::GenVertexArray(1, &m_VAO);
    OpenGL::GenBuffers(1, &m_VBO);
    APP_ASSERT(m_VBO > 0 && m_VAO > 0 && "Vertex Array Object or Vertex Array Buffer could not initialized.");

    /* Bind Vertex Array */
    OpenGL::BindVertexArray(m_VAO);
    OpenGL::BindBuffer(GL_ARRAY_BUFFER, m_VBO);
    OpenGL::BufferData(GL_ARRAY_BUFFER, (m_Verticies.size() * sizeof(glm::vec2)), &m_Verticies[0], GL_STATIC_DRAW);

    /* Set Vertex Attributes */
    OpenGL::VertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
    OpenGL::EnableVertexAttribArray(0);

    /* Disable Array Object */
    OpenGL::BindVertexArray(0);    
}
