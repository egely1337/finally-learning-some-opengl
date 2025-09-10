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
    m_Texture.Bind();
    m_Shader.Bind();

    m_Shader.SetUniform1i("Texture", TEXTURE_0);
    m_Shader.SetUniform4f("MVP", (const GLfloat*)&m_Camera.GetCameraMatrix()[0][0]);
    m_Shader.SetUniform1f("Scale", Scale());

    /* Draw */
    OpenGL::BindVertexArray(m_VAO);
    OpenGL::DrawArrays(GL_TRIANGLES, 0, m_Verticies.size());

    /* Unbind */
    OpenGL::BindVertexArray(0);
    m_Texture.Unbind();
    m_Shader.Unbind();
}

void Mesh::Bind()
{
    /* Verticies */
    m_Verticies.push_back(Vertex2f{
        .Position = glm::vec2(-1.0f, 0.0f),
        .Color = glm::vec3(1.0f, 0.0f, 0.0f),
        .TexPosition = glm::vec2(0.0f, 0.0f) 
    });

    m_Verticies.push_back(Vertex2f{
        .Position = glm::vec2(1.0f, 0.0f),
        .Color = glm::vec3(1.0f, 0.0f, 0.0f),
        .TexPosition = glm::vec2(1.0f, 0.0f)
    });

    m_Verticies.push_back(Vertex2f{
        .Position = glm::vec2(0.0f, 1.0f),
        .Color = glm::vec3(1.0f, 0.0f, 0.0f),
        .TexPosition = glm::vec2(0.5f, 1.0f)
    });

    APP_ASSERT(m_Verticies.size() > 0 && "You should set verticies first.");

    /* Load Texture */
    m_Texture.Load("texture/hello.png");

    /* Create VAO and VBO. */
    OpenGL::GenVertexArray(1, &m_VAO);
    OpenGL::GenBuffers(1, &m_VBO);
    APP_ASSERT(m_VBO > 0 && m_VAO > 0 && "Vertex Array Object or Vertex Array Buffer could not initialized.");

    /* Bind Vertex Array */
    OpenGL::BindVertexArray(m_VAO);
    OpenGL::BindBuffer(GL_ARRAY_BUFFER, m_VBO);
    OpenGL::BufferData(GL_ARRAY_BUFFER, (m_Verticies.size() * sizeof(Vertex2f)), &m_Verticies[0], GL_STATIC_DRAW);

    /* Set Vertex (Position) Attributes */
    OpenGL::VertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2f), NULL);
    OpenGL::EnableVertexAttribArray(0);

    /* Set Vertex (Color) Attributes */
    OpenGL::VertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2f), (const GLvoid*)offsetof(Vertex2f, Color));
    OpenGL::EnableVertexAttribArray(1);

    /* Set Vertex (Texture Position) Attributes */
    OpenGL::VertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2f), (const GLvoid*)offsetof(Vertex2f, TexPosition));
    OpenGL::EnableVertexAttribArray(2);

    /* Disable Array Object */
    OpenGL::BindVertexArray(0);
}

void Mesh::Destroy() {
    /* Clean up verticies. */
    m_Verticies.clear();

    /* Clean up VAO and VBO */
    assert(m_VAO > 0 && m_VBO > 0 && "You can't destroy a mesh you didn't even create.");

    /* Clean up OpenGL */
    OpenGL::DeleteBuffers(1, &m_VBO);
    OpenGL::DeleteArrays(1, &m_VAO);
}