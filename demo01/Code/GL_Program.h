#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "IShader.h"

class GL_Program
{
public:
	GL_Program();
	void attachShader(IShader& shader);
	void attachShader(IShader&& shader);
	void linkProgram();
	unsigned getProgram();
private:
	unsigned program;
};

