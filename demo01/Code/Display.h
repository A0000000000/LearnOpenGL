#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "IDraw.h"
class Display
{
public:
	Display(int width, int height, std::string title);
	void setFramebufferSizeCallback(void(*callback)(GLFWwindow* window, int width, int height)) const;
	void makeThisContextCurrent() const;
	void addDraw(IDraw* draw);
	void update();
	void dispose();
	
private:
	GLFWwindow* window;
	std::vector<IDraw*> draws;
};

