#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class IShader
{
public:
	void virtual createShader() = 0;
	unsigned virtual getShader() = 0;
	void virtual setSourceCode(const char* source) = 0;
	void virtual compileShader() = 0;
	void virtual deleteShader() = 0;
};

