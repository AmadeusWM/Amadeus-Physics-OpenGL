#include "../../include/spring_mass/mass_cube.h"
#include "math.h"

/**
 * @brief Construct a new Mass Cube:: Mass Cube object
 *
 * @param pos
 * @param mass
 * @param fh
 * @param fd
 */
MassCube::MassCube(glm::vec3 pos, float mass)
    : m_position{pos}, m_positionPrev{pos}, m_mass{mass}
{
    m_cube = new ShapeCube{pos};
}

/**
 * @brief Calculate the hooke force currently affecting the mass cube
 *
 * @param springAbove
 * @param springBelow
 */
void MassCube::calcHookeTopSpring(Spring *spring)
{
    float hookeAbove = -spring->calcHookeForce();

    // (hookeforce top spring * direction) - (hookeforce lower spring * direction)
    std::cout<< "hooke force: " << hookeAbove << std::endl;
    m_forceHooke = hookeAbove * spring->getDirection();
}


/**
 * @brief Calculate the hooke force currently affecting the mass cube
 *
 * @param springAbove
 * @param springBelow
 */
void MassCube::calcHookeBottomSpring(Spring *spring)
{
    float hookeBelow = spring->calcHookeForce();

    // (hookeforce top spring * direction) - (hookeforce lower spring * direction)
    std::cout<< "hooke force: " << hookeBelow << std::endl;
    m_forceHooke += hookeBelow * spring->getDirection();
}

/**
 * @brief Apply the hooke and damping force on this mass cube, and change the position
 *
 */
void MassCube::applyForces()
{
    glm::vec3 acceleration = m_forceHooke / m_mass;
    glm::vec3 temp = m_position;
    m_position = (2.0f * m_position - m_positionPrev + (acceleration + F_GRAVITY)  * (float)pow(0.03f, 2));
    m_positionPrev = temp;
    m_cube->setPosition(m_position);
}

/**
 * @brief Draw a cube
 *
 * @param shader
 */
void MassCube::draw(Shader *shader)
{
    m_cube->draw(shader);
}

/**
 * @brief returns the position of the mass cube
 *
 * @return glm::vec3
 */
glm::vec3 MassCube::getPosition()
{
    return m_position;
}