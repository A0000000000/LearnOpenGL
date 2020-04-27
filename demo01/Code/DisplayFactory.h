#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Display.h"

class DisplayFactory
{
public:
	static void init(int minor, int major);
	static void setAttribute(int hint, int value);
	static Display* createDisplay(int width, int height, std::string title);
	static void disposeDisplay(Display* display);
	static void loadGLLoader();
	static void dispose();
};

