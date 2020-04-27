#include "VertexShader.h"

void VertexShader::createShader()
{
	this->shader = glCreateShader(GL_VERTEX_SHADER);
}

unsigned VertexShader::getShader()
{
	return this->shader;
}

void VertexShader::setSourceCode(const char* source)
{
	this->source = source;
	glShaderSource(this->shader, 1, &this->source, nullptr);
}

void VertexShader::compileShader()
{
	glCompileShader(this->shader);
}

void VertexShader::deleteShader()
{
	glDeleteShader(this->shader);
}
