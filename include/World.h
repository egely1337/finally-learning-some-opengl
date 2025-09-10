#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include <Definitions.h>
#include <GL.h>

class World {
protected:
    std::vector<void*> m_Components;
    std::vector<void*> m_MeshComponents;
public:
    World();
    ~World();
    void Update();
    void Initialize();
};

#endif