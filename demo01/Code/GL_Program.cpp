#include "GL_Program.h"

GL_Program::GL_Program()
{
	this->program = glCreateProgram();
}

void GL_Program::attachShader(IShader& shader)
{
	glAttachShader(this->program, shader.getShader());
}

void GL_Program::attachShader(IShader&& shader)
{
	glAttachShader(this->program, shader.getShader());
}

void GL_Program::linkProgram()
{
	glLinkProgram(this->program);
}

unsigned GL_Program::getProgram()
{
	return this->program;
}
