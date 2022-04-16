#pragma once
// math
#include <glm/glm.hpp>
// c++ libs
#include <vector>
// headers
#include "./spring.h"
#include "./mass_cube.h"
#include "../opengl/shader.h"

class SpringsConnected{
    private:
        std::vector<MassCube*> m_massCubes;
        std::vector<Spring*> m_springs;
    public:
        SpringsConnected(int amSprings, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f});
        void applyForces();
        void draw(Shader* shader);
};