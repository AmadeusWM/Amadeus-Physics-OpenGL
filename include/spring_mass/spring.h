#pragma once
#include <glm/glm.hpp>

class Spring {
    private:
        float m_length;
        float m_lengthPrev;
        glm::vec3 m_point1;
        glm::vec3 m_point2;

    public:
        Spring(glm::vec3 point1, glm::vec3 point2, float restLength, float SPRING_STRENGTH);
        
        const float SPRING_REST_LENGTH;
        const float SPRING_STRENGTH;

        void setPoints(glm::vec3 point1, glm::vec3 point2);
        float getLength() const;
        float getLengthPrev() const;

        float calcHookeForce();

        glm::vec3 getDirection() const;
};