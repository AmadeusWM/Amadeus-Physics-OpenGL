#pragma once
// OPENGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// c++ functions
#include <vector>
// headerfiles project
#include "../include/opengl/shader.h"
#include "../include/shapes/shape_cube.h"

class Game{
    private:
    // member variables
        GLFWwindow* m_window;
        Shader* m_shader;

        std::vector<ShapeCube*> m_cubes;
    // functions
        void processInput();
        void render();
    public:
        Game(int windowWidth, int windowHeight);
        ~Game();
        void renderLoop();
};