#include "../../include/shapes/shape.h"

Shape::Shape(glm::vec3 pos, glm::vec4 color, glm::vec3 rotation, glm::vec3 scale)
    : m_position{pos}, m_color{color}, m_rotation{rotation}, m_scale{scale}
{
    
}

/**
 * @brief sets the current position of the shape
 * 
 * @param pos 
 */
void Shape::setPosition(glm::vec3 pos){
    m_position = pos;
}

/**
 * @brief sets the current rotation of the shape
 * 
 * @param rotation 
 */
void Shape::setRotation(glm::vec3 rotation) {
    m_rotation = rotation;
}

/**
 * @brief sets the current scale of the shape
 * 
 * @param scale 
 */
void Shape::setScale(glm::vec3 scale){
    m_scale = scale;
}