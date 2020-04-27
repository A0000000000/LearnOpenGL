#include "Display.h"

Display::Display(int width, int height, std::string title)
{
	this->window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
}

void Display::setFramebufferSizeCallback(void(*callback)(GLFWwindow* window, int width, int height)) const
{
	glfwSetFramebufferSizeCallback(window, callback);
}

void Display::makeThisContextCurrent() const
{
	glfwMakeContextCurrent(this->window);
}

void Display::addDraw(IDraw* draw)
{
	this->draws.push_back(draw);
}



void Display::update()
{
	while (!glfwWindowShouldClose(this->window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		for (IDraw* draw : this->draws)
		{
			draw->draw();
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Display::dispose()
{
	for (IDraw* draw : draws)
	{
		draw->dispose();
	}
}
