#include <Camera2D.h>


Camera2D::Camera2D(float Width, float Height):
    m_ProjectionMatrix(glm::ortho(-Width, Width, -Height, Height, -1.f, 1.f))
{
    glm::mat4 Transform = glm::translate(glm::mat4(1.f), m_CameraPos) * glm::rotate(glm::mat4(1.f), m_CameraRotation, glm::vec3(0, 0, 1));
    m_ViewMatrix = glm::inverse(Transform);
}

Camera2D::~Camera2D() {
    NOT_IMPLEMENTED();
}

void Camera2D::Update()
{
    glm::mat4 Transform = glm::translate(glm::mat4(1.f), m_CameraPos) * glm::rotate(glm::mat4(1.f), m_CameraRotation, glm::vec3(0, 0, 1));
    m_ViewMatrix = glm::inverse(Transform);
}

glm::mat4 Camera2D::GetCameraMatrix()
{
    return (glm::mat4)m_ProjectionMatrix * m_ViewMatrix;
}
