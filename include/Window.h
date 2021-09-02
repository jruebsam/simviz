#pragma  once 

#include "glad/glad.h"

#include <GLFW/glfw3.h>

class Window {
private:
  GLFWwindow* _window{nullptr};
  int width{};
  int height{};

  static void resizeCallback(GLFWwindow* window, int width, int height);

public:
  Window(int width, int height);

  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;

  ~Window();

  bool isRendering();

  void update();


};
