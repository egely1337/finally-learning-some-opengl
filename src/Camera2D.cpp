#include <Camera2D.h>


Camera2D::Camera2D() {
    m_ProjectionMatrix = glm::ortho(-1, 1, -1, 1);
    
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
    return m_ProjectionMatrix * m_ViewMatrix;
}
