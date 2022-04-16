#include "../include/game.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

/**
 * @brief Construct a new Game:: Game object
 *
 * @param windowWidth : width of the game window
 * @param windowHeight : height of the game window
 */
Game::Game(int windowWidth, int windowHeight)
{
    glfwInit();                                                    // initialize GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);                 // version 3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);                 // version 3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // we use the core profile (GLAD)

    m_window = glfwCreateWindow(windowWidth, windowHeight, "Spring Mass Simulator", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create a GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD." << std::endl;
        glfwTerminate();
        exit(3);
    }
    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    glEnable(GL_DEPTH_TEST);
    // init shader objects
    m_shader = new Shader{"./shaders/shader.vert", "./shaders/shader.frag"};
    m_shader->use();
    // init perspective projection matrix
    glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)windowWidth/(float)windowHeight, 0.1f, 100.0f);
    m_shader->setMatrix4fv("projection", proj);
}

Game::~Game(){
    delete m_shader;
}

void Game::renderLoop(){
    for (int i = -5 ; i < 5; i++){
        m_cubes.push_back(new ShapeCube(glm::vec3{0.0f,(float)(i*2), 0.0f}));
    }

    while(!glfwWindowShouldClose(m_window)){
        // input
        processInput();
        
        // rendering commands
        
        glClearColor(0.2f, 0.3f, 0.2f, 1.0f); // sets the clear color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // uses clear color
        // do main functions
        render();
        
        // check and call events and swap the buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
    glfwTerminate();
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Game::processInput()
{
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}
/**
 * @brief : Draw every object and determine view matrix
 * 
 */
void Game::render(){
    m_shader->use();
    
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f)); // reverse direction of where we want to go

    m_shader->setMatrix4fv("view", view);

    for (const auto cube : m_cubes){
        cube->draw(m_shader);
    }
}

/**
 * @brief changes the width and height of the viewport from the current window
 *
 * @param window : current window
 * @param width : new width
 * @param height : new height
 */
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}