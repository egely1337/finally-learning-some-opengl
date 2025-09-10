#ifndef VERTEX_H
#define VERTEX_H
#include <glm/glm.hpp>
struct Vertex2f {
    glm::vec2 Position;
    glm::vec3 Color;
    glm::vec2 TexPosition;
};

struct Vertex3f {
    glm::vec3 Position;
    glm::vec3 Color;
    glm::vec3 TexPosition;
};
#endif