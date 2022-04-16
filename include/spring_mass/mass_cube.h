#pragma once
// math
#include <glm/glm.hpp>
// project headers
#include "../shapes/shape_cube.h"
#include "../opengl/shader.h"
#include "./spring.h"


class MassCube {
    private:
        const glm::vec3 F_GRAVITY{0.0f, -9.81, 0.0f};

        ShapeCube* m_cube; // instance of the cube shape

        glm::vec3 m_position;
        glm::vec3 m_positionPrev;

        float m_mass;
        
        glm::vec3 m_forceHooke{0.0f, 0.0f, 0.0f};
        glm::vec3 m_forceDamping{0.0f, 0.0f, 0.0f};
    public:
        MassCube(glm::vec3 pos, float mass);
        ~MassCube();

        void calcHookeTopSpring(Spring *spring);
        void calcHookeBottomSpring(Spring *spring);
        void calcDamping(Spring* springBelow, Spring* springAbove);
        
        void applyForces();

        void draw(Shader* shader);

        glm::vec3 getPosition();
};