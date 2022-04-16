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
#include "../include/opengl/camera.h"
#include "../include/spring_mass/springs_connected.h"

class Game{
    private:
    // member variables
        GLFWwindow* m_window;
        Shader* m_shader;
        Camera* m_camera;

        std::vector<SpringsConnected*> m_connectedSprings;
        
        double xPosCursor, yPosCursor;
    // functions
        void processInput();
        void render();
    public:
        Game(int windowWidth, int windowHeight);
        ~Game();
        void renderLoop();
};