#pragma once
#include "shape.h"

class ShapeCube : public Shape {
    private:

    public:
        ShapeCube(glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, 
                glm::vec4 color = glm::vec4{0.0f, 0.0f, 0.0f, 1.0f}, 
                glm::vec3 rotation = glm::vec3{0.0f, 0.0f, 0.0f},
                glm::vec3 scale = glm::vec3{1.0f, 1.0f, 1.0f}); 
        void draw(Shader* shader) override;
};