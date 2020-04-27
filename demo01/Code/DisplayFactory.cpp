#include "DisplayFactory.h"

void DisplayFactory::init(int minor, int major)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
}

void DisplayFactory::setAttribute(int hint, int value)
{
	glfwWindowHint(hint, value);
}

Display* DisplayFactory::createDisplay(int width, int height, std::string title)
{
	return new Display(width, height, title);
}

void DisplayFactory::disposeDisplay(Display* display)
{
	display->dispose();
	delete display;
}


void DisplayFactory::loadGLLoader()
{
	gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
}

void DisplayFactory::dispose()
{
	glfwTerminate();
}
