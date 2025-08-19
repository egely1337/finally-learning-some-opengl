#ifndef CAMERA_3D_H
#define CAMERA_3D_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Definitions.h>

class Camera3D {
protected:
    glm::mat4 m_ViewMatrix = glm::mat4(1.f);
    glm::mat4 m_ProjectionMatrix = glm::mat4(1.f);
    glm::vec3 m_CameraPos = glm::vec3(0.f, 0.f, 0.f);
    glm::vec3 m_CameraRotation = glm::vec3(0.f, 0.f, 0.f);
public:
    Camera3D();
    ~Camera3D();
    FORCEINLINE glm::mat4& GetViewMatrix() { return m_ViewMatrix; }
    FORCEINLINE glm::mat4& GetProjectionMatrix() { return m_ProjectionMatrix; }
};


#endif