#include "../../include/spring_mass/spring.h"
#include <iostream>


/**
 * @brief Construct a new Spring:: Spring object
 * 
 * @param point1 
 * @param point2 
 * @param restLength 
 */
Spring::Spring(glm::vec3 point1, glm::vec3 point2, float restLength, float springLength)
    : m_point1{point1}, m_point2{point2}, SPRING_REST_LENGTH{restLength}, SPRING_STRENGTH{springLength}
{
    m_length = glm::distance(point1, point2);
    m_lengthPrev = m_length;
}

/**
 * @brief Set the upper and the lower point of the spring (in space)
 *        And change the prev and curr length
 * 
 * @param point1 
 * @param point2 
 */
void Spring::setPoints(glm::vec3 point1, glm::vec3 point2){
    m_point1 = point1;
    m_point2 = point2;
    // calculate new lengths
    m_lengthPrev = m_length;
    m_length = glm::distance(point1, point2);
}

/**
 * @brief returns the current length
 * 
 * @return float 
 */
float Spring::getLength() const{
    return m_length;
}

/**
 * @brief returns the previous length of the spring
 * 
 * @return float 
 */
float Spring::getLengthPrev() const{
    return m_lengthPrev;
}
/**
 * @brief 
 * 
 * @return float 
 */
float Spring::calcHookeForce(){
    float hookeForce = SPRING_STRENGTH * (m_length - SPRING_REST_LENGTH);
    return hookeForce;
}

/**
 * @brief Get the normalized direction of the spring
 * 
 * @return float 
 */
glm::vec3 Spring::getDirection() const{
    return glm::normalize(m_point2 - m_point1);
}
