#pragma once

// OPENGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// shaders
#include "../opengl/shader.h"

// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
 * @brief Generate a shape with a position, color, rotation,...
 * 
 */
class Shape{
    protected:
        glm::vec3 m_position;
        glm::vec3 m_rotation;
        glm::vec3 m_scale;

        glm::vec4 m_color;

        unsigned int VAO; // the Vertex Array Object
    public:
        // constructor
        Shape(glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, 
                glm::vec4 color = glm::vec4{0.0f, 0.0f, 0.0f, 1.0f}, 
                glm::vec3 rotation = glm::vec3{0.0f, 0.0f, 0.0f},
                glm::vec3 scale = glm::vec3{1.0f, 1.0f, 1.0f}); 
        void setPosition(glm::vec3 pos);
        void setRotation(glm::vec3 rotation);
        void setScale(glm::vec3 scale);

        virtual void draw(Shader* shader) = 0;
};