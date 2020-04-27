#include "FragmentShader.h"

void FragmentShader::createShader()
{
	this->shader = glCreateShader(GL_FRAGMENT_SHADER);
}

unsigned FragmentShader::getShader()
{
	return this->shader;
}

void FragmentShader::setSourceCode(const char* source)
{
	this->source = source;
	glShaderSource(this->shader, 1, &this->source, nullptr);
}

void FragmentShader::compileShader()
{
	glCompileShader(this->shader);
}

void FragmentShader::deleteShader()
{
	glDeleteShader(this->shader);
}
