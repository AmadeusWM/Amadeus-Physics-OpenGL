#include "../../include/shapes/shape_cube.h"

/**
 * @brief Construct a new Shape Cube:: Shape Cube object
 * 
 * @param pos 
 * @param color 
 * @param rotation 
 */
ShapeCube::ShapeCube(glm::vec3 pos, glm::vec4 color, glm::vec3 rotation, glm::vec3 scale)
    : Shape{pos, color, rotation, scale}
{
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, 0.5f, -0.5f, 
        0.5f, 0.5f, -0.5f, 
        -0.5f, 0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f, -0.5f, 0.5f, 
        0.5f, -0.5f, 0.5f, 
        0.5f, 0.5f, 0.5f, 
        0.5f, 0.5f, 0.5f, 
        -0.5f, 0.5f, 0.5f, 
        -0.5f, -0.5f, 0.5f, 

        -0.5f, 0.5f, 0.5f, 
        -0.5f, 0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f, 

        0.5f, 0.5f, 0.5f, 
        0.5f, 0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, 0.5f, 
        0.5f, 0.5f, 0.5f, 

        -0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, 0.5f, 
        0.5f, -0.5f, 0.5f, 
        -0.5f, -0.5f, 0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, -0.5f, 
        0.5f, 0.5f, 0.5f, 
        0.5f, 0.5f, 0.5f, 
        -0.5f, 0.5f, 0.5f, 
        -0.5f, 0.5f, -0.5f, };
    // generate vertex arrays object and vertex buffer object
    glGenVertexArrays(1, &VAO);

    unsigned int VBO; // id of VBO
    glGenBuffers(1, &VBO);
    // bind VAO
    glBindVertexArray(VAO);
    // copy vertices array in buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0); // enables the vertex attribute

    // unbind VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // unbind VAO
    glBindVertexArray(0);
}

void ShapeCube::draw(Shader* shader){
    // set model matrix
    glm::mat4 model = glm::mat4{1.0f};
    // translate
    model = glm::translate(model, m_position);
    // // rotate
    model = glm::rotate(model, m_rotation.x, glm::vec3{1.0f, 0.0f, 0.0f}); // rotate around the x-axis
    model = glm::rotate(model, m_rotation.y, glm::vec3{0.0f, 1.0f, 0.0f}); // rotate around the y-axis
    model = glm::rotate(model, m_rotation.z, glm::vec3{0.0f, 0.0f, 1.0f}); // rotate around the z-axis
    // // scale
    // model = glm::scale(model, m_scale);
    model = glm::scale(model, glm::vec3{1.0f, 1.0f, 1.0f});

    // set the model uniform
    shader->use();
    shader->setMatrix4fv("model", model);

    // bind vao
    glBindVertexArray(VAO);
    // draw the cube
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}