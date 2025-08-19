#include <Shader.h>

Shader::Shader()
{
    NOT_IMPLEMENTED();
}

Shader::~Shader()
{
    NOT_IMPLEMENTED();
}

bool Shader::CreateShaderFromSource(std::string VertexShaderSrc, std::string FragmentShaderSrc)
{
    /* Create shader and its program. */
    std::string *VertexShader = new std::string(VertexShaderSrc.c_str());
    std::string *FragmentShader = new std::string(FragmentShaderSrc.c_str());

    const char* vertex = VertexShader->c_str();
    const char* fragment = FragmentShader->c_str();

    /* Create shader and compile */
    GLuint VertexShaderId = glCreateShader(APP_VERTEX_SHADER);
    OpenGL::ShaderSource(VertexShaderId, 1, &vertex, NULL);
    OpenGL::CompileShader(VertexShaderId);
    GLuint FragmentShaderId = glCreateShader(APP_FRAGMENT_SHADER);
    OpenGL::ShaderSource(FragmentShaderId, 1, &fragment, NULL);
    OpenGL::CompileShader(FragmentShaderId);

    /* Check shader compile errors. */
    GLint success;
    glGetShaderiv(VertexShaderId, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(VertexShaderId, 512, NULL, m_ErrorMsg);
        fprintf(stderr, "Shader Compilation Error: %s\n" ,m_ErrorMsg);
        return false;
    }

    /* Create shader program */
    m_ProgramId = OpenGL::CreateProgram();
    OpenGL::AttachShader(m_ProgramId, VertexShaderId);
    OpenGL::AttachShader(m_ProgramId, FragmentShaderId);
    OpenGL::LinkProgram(m_ProgramId);

    /* Delete unneccesary shaders */
    OpenGL::DeleteShader(VertexShaderId);
    OpenGL::DeleteShader(FragmentShaderId);

    delete FragmentShader;
    delete VertexShader;
    
    return (m_ProgramId > 0) ? true : false;
}

void Shader::SetUniform4f(std::string Name, const GLfloat* Matrix4f) {
    APP_ASSERT(m_ProgramId > 0 && "You should compile shader first.");
    OpenGL::SetUniformMatrix4f(m_ProgramId, Name, Matrix4f);
}

void Shader::SetUniform1f(std::string Name, GLfloat Val)
{
    APP_ASSERT(m_ProgramId > 0 && "You should compile shader first.");
    OpenGL::SetUniform1f(m_ProgramId, Name, Val);
}

void Shader::Bind()
{
    OpenGL::UseProgram(m_ProgramId);
}

void Shader::Unbind()
{
    OpenGL::UseProgram(0);
}

void Shader::Destroy()
{
    OpenGL::DeleteProgram(m_ProgramId);
}