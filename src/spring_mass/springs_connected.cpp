#include "../../include/spring_mass/springs_connected.h"

/**
 * @brief Construct a new Springs Connected:: Springs Connected object
 *
 * @param amSprings
 */
SpringsConnected::SpringsConnected(int amSprings, glm::vec3 pos)
{
    float totalLength = 0.0f;
    float horizontalOffset = 0.0f;
    float zOffset = 0.0f;

    float springLength = 0.9f;
    float springForce = 10.0f;

    glm::vec3 posPrev = pos;
    m_massCubes.push_back(new MassCube(posPrev, 0.0f));
    for (int i = 0; i < amSprings; i++)
    {
        // get a random length
        float randomLength = ((float)(rand() % 5 + springLength));
        // increment total length and horizontal offset
        totalLength -= randomLength;
        horizontalOffset += randomLength;
        zOffset += randomLength;
        // position of cubes
        glm::vec3 pos{horizontalOffset, totalLength, zOffset};
        // add new spring
        m_springs.push_back(new Spring(posPrev, pos, springLength, springForce));
        // add new cube
        m_massCubes.push_back(new MassCube(pos, 0.5f));
        posPrev = pos;
    }
}

void SpringsConnected::applyForces()
{
    int vectLength = m_massCubes.size();
    // calculate the hooke force affecting the cubes
    for (int i = 1; i < vectLength - 1; i++)
    {
        m_massCubes[i]->calcHookeTopSpring(m_springs[i - 1]);
        m_massCubes[i]->calcHookeBottomSpring(m_springs[i]);
    }
    m_massCubes[vectLength-1]->calcHookeTopSpring(m_springs[vectLength-2]);
    // apply all the forces that were calculated on every cube
    for (int i = 1; i < vectLength; i++)
    {
        m_massCubes[i]->applyForces();
    }
    for (int i = 0; i < m_springs.size(); i++){
        m_springs[i]->setPoints(m_massCubes[i]->getPosition(), m_massCubes[i+1]->getPosition());
    }
}

/**
 * @brief Draw the connected springs with cubes between them
 *
 * @param shader
 */
void SpringsConnected::draw(Shader *shader)
{
    for (auto const cube : m_massCubes)
    {
        cube->draw(shader);
    }
}