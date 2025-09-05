#include <Mesh.h>

Mesh::Mesh() : m_Camera(800, 600)
{
    APP_ASSERT(&m_Camera && "Camera should be initialized.");
}

Mesh::~Mesh()
{
    m_Shader.Destroy();
}

void Mesh::Draw()
{
    /* Update Camera */
    m_Camera.Update();

    /* Shader */
    m_Shader.Bind();
    m_Shader.SetUniform4f("MVP", (const GLfloat*)&m_Camera.GetCameraMatrix()[0]);
    m_Shader.SetUniform1f("Scale", Scale());

    /* Draw */
    OpenGL::BindVertexArray(m_VAO);
    OpenGL::DrawArrays(GL_POLYGON, 0, m_Verticies.size());

    /* Unbind */
    OpenGL::BindVertexArray(0);
    m_Shader.Unbind();
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

void Mesh::Destroy() {
    /* Clean up verticies. */
    m_Verticies.clear();

    /* Clean up VAO and VBO */
    assert(m_VAO > 0 && m_VBO > 0 && "You can't destroy a mesh you didn't even create.");

    OpenGL::DeleteBuffers(1, &m_VBO);
    OpenGL::DeleteArrays(1, &m_VAO);
}

void Mesh::CompileShader(std::string& VertexShader, std::string& FragmentShader) {
    APP_ASSERT(m_Shader.CreateShaderFromSource(VertexShader, FragmentShader) && "Shader could not be compiled.");    
}

void Mesh::SetScale(GLfloat NewScale)
{
    m_MeshScale = NewScale;
}
