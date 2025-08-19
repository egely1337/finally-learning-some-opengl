#ifndef CAMERA_2D_H
#define CAMERA_2D_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Definitions.h>

class Camera2D {
public:
    Camera2D();
    ~Camera2D();

    void Update();
    glm::mat4 GetCameraMatrix();
    FORCEINLINE glm::vec3& CameraPosition() {return m_CameraPos;}
    FORCEINLINE float& CameraRotation() {return m_CameraRotation;}

protected:
    /* Projection&View Attributes */
    glm::mat4 m_ProjectionMatrix = glm::mat4(1.f);
    glm::mat4 m_ViewMatrix = glm::mat4(1.f);

    /* Camera Attributes */
    glm::vec3 m_CameraPos = glm::vec3(0.f, 0.f, 0.f);
    float m_CameraRotation = 0.f;
};


#endif