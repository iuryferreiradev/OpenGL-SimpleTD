#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void error_callback(int error, const char* description)
{
  std::cout << "ERROR::GLFW::CALLBACK: " << description << std::endl;
}

const glm::vec4 CLEAR_COLOR = glm::vec4(glm::vec3(0.0f), 1.0f);

int main()
{
  // Error callback that is called when there is an error in the glfw lib
  glfwSetErrorCallback(error_callback);

  // Window manager library initialization
  if(!glfwInit())
  {
    std::cout << "ERROR::GLFW::INIT" << std::endl;
    return -1;
  }

  // Specify opengl version and profile
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Window creation
  GLFWwindow *window = glfwCreateWindow(800, 600, "Simple TD", NULL, NULL);
  if(!window)
  {
    std::cout << "ERROR::GLFW::WINDOW" << std::endl;
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Loading opengl 
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "ERROR::GLAD::LOAD_OPENGL" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);

  while(!glfwWindowShouldClose(window))
  {
    // Watch for the events like the events that close the window, keyboard, gamepad...
    glfwPollEvents();
    // Sets the clear color, the context will be cleared using this color
    glClearColor(CLEAR_COLOR.x, CLEAR_COLOR.y, CLEAR_COLOR.z, CLEAR_COLOR.w);
    // Clearing only the color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    // Swaps the front with the back buffer
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}