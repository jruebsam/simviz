#include "Window.h"

#include <iostream>
#include <stdexcept>

Window::Window(int width, int height) : width{width}, height{height}
{
  if(!glfwInit()){
    throw  std::runtime_error("Failed to create initialize GLFW");
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_OPENGL_CORE_PROFILE);

  _window = glfwCreateWindow(width, height, "SimCanvas", nullptr, nullptr);

  if(_window == nullptr) {
    glfwTerminate();
    throw  std::runtime_error("Failed to create rendering canvas");
  }

  glfwMakeContextCurrent(_window);
  
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    throw  std::runtime_error("Failed to initialize GLAD");
  }    

  glViewport(0, 0, width, height);
  glfwSetFramebufferSizeCallback(_window, resizeCallback);

};


Window::~Window() {
  glfwTerminate();
}


void Window::resizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
};

  
bool Window::isRendering() {
  return !glfwWindowShouldClose(_window);
}

void Window::update() {
  glfwSwapBuffers(_window);
  glfwPollEvents();
}

