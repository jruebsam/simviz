#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <memory>

#include "Window.h"

int main() {
  std::unique_ptr<Window> mainWindow; 

  try {
    mainWindow = std::make_unique<Window>(800, 600);
  } 
  catch(const std::exception &e) {
    std::cout << e.what() << std::endl;
    return -1;
  }

  while(mainWindow->isRendering()) {
    mainWindow->update();
  }


  return 0;
}
